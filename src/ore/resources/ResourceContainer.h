#pragma once

#include <string>
#include <map>
#include <ore/utilities/filesystem.h>
#include <ore/resources/ResourceLoadPriority.h>
#include <cassert>
#include <iostream>
#include <queue>
#include <mutex>
#include <g3log/g3log.hpp>

namespace ore {
    namespace resources {
        template<typename ResourceType>
        struct ResourceContainerEntry {
            bool isLoaded = false;
            ResourceType* content = nullptr;
            ore::resources::ResourceLoadPriority priority = ResourceLoadPriority::REQUIRED;
            ore::filesystem::path fileLocation;
        };

        template<typename ContentsType>
        class ResourceContainer {
            friend class ResourceCache;

        private:
            std::map<std::string, ore::resources::ResourceContainerEntry<ContentsType>> resourceMap;
            std::queue<std::string> requiredLoadingQueue;
            std::queue<std::string> streamLoadingQueue;
            std::queue<std::string> mainThreadCompletionQueue;
            std::mutex loadingQueueMutex;
            std::mutex mainThreadQueueMutex;
            unsigned int requiredItemsInProgress = 0;
            unsigned int streamingItemsInProgress = 0;

            void loadEntry(const std::string &entryID, bool isMainThread) {
                typename std::map<std::string, ore::resources::ResourceContainerEntry<ContentsType>>::iterator
                    entry = resourceMap.find(entryID);
                ore::resources::ResourceType* resourceType = entry->second.content;
                // Some order of events exist where a resource is loaded before a loading
                // thread can get to it. So we do a check here just in case.
                if(entry->second.isLoaded) {
                    std::cout << "Entry is already loaded, exiting.." << std::endl;
                    return;
                }

                resourceType->load(entry->second.fileLocation);

                if(resourceType->requiresMainThread() && !isMainThread) {
                    mainThreadQueueMutex.lock();
                    mainThreadCompletionQueue.push(entryID);
                    mainThreadQueueMutex.unlock();
                } else if(resourceType->requiresMainThread() && isMainThread) {
                    resourceType->completeLoadOnMainThread();
                    entry->second.isLoaded = true;

                    #pragma omp atomic
                    requiredItemsInProgress--;
                } else {
                    entry->second.isLoaded = true;
                    #pragma omp atomic
                    requiredItemsInProgress--;
                }
            }

            void runMainThreadJobs() {
                mainThreadQueueMutex.lock();
                while(!mainThreadCompletionQueue.empty()) {
                    std::string nextEntry = mainThreadCompletionQueue.front();
                    mainThreadCompletionQueue.pop();
                    typename std::map<std::string, ore::resources::ResourceContainerEntry<ContentsType>>::iterator
                            entry = resourceMap.find(nextEntry);
                    ore::resources::ResourceType* resourceType = entry->second.content;
                    resourceType->completeLoadOnMainThread();
                    entry->second.isLoaded = true;
                    #pragma omp atomic
                    requiredItemsInProgress--;
                }
                mainThreadQueueMutex.unlock();
            }

            unsigned int getEnqueuedItemCount(ore::resources::ResourceLoadPriority threshold) {
                unsigned int enqueuedItemCount = 0;
                if(threshold == ore::resources::ResourceLoadPriority::REQUIRED) {
                    enqueuedItemCount += requiredItemsInProgress;
                }
                if((threshold == ore::resources::ResourceLoadPriority::STREAMING ||
                    threshold == ore::resources::ResourceLoadPriority::REQUIRED)) {
                    enqueuedItemCount += streamingItemsInProgress;
                }
                return enqueuedItemCount;
            }

            bool loadNext(ore::resources::ResourceLoadPriority threshold) {
                loadingQueueMutex.lock();
                if((threshold == ore::resources::ResourceLoadPriority::STREAMING ||
                    threshold == ore::resources::ResourceLoadPriority::REQUIRED) &&
                   !requiredLoadingQueue.empty()) {
                    std::string nextEntry = requiredLoadingQueue.front();
                    requiredLoadingQueue.pop();
                    loadingQueueMutex.unlock();
                    loadEntry(nextEntry, false);
                    return true;
                }
                if((threshold == ore::resources::ResourceLoadPriority::STREAMING) &&
                   !streamLoadingQueue.empty()) {
                    std::string nextEntry = streamLoadingQueue.front();
                    streamLoadingQueue.pop();
                    loadingQueueMutex.unlock();
                    loadEntry(nextEntry, false);
                    return true;
                }
                loadingQueueMutex.unlock();
                return false;
            }

            void evict(const std::string &itemID) {

            }

        public:
            void registerResource(std::string itemID, ore::resources::ResourceLoadPriority priority, ore::filesystem::path fileLocation, ContentsType* contentsTypeInstance) {
                LOG(INFO) << "Registering resource: " << itemID << ". Src: " << fileLocation.string() << std::endl;
                contentsTypeInstance->setName(itemID);
                if(priority == ResourceLoadPriority::REQUIRED) {
                    #pragma omp atomic
                    requiredItemsInProgress++;
                }
                ore::resources::ResourceContainerEntry<ContentsType> entry;
                entry.fileLocation = fileLocation;
                entry.priority = priority;
                entry.content = contentsTypeInstance;
                if(this->resourceMap.find(itemID) == this->resourceMap.end()) {
                    loadingQueueMutex.lock();
                    this->resourceMap[itemID] = entry;
                    if(priority == ore::resources::ResourceLoadPriority::REQUIRED) {
                        requiredLoadingQueue.emplace(itemID);
                    }
                    if(priority == ore::resources::ResourceLoadPriority::STREAMING) {
                        streamLoadingQueue.emplace(itemID);
                    }
                    loadingQueueMutex.unlock();
                }
            }

            ContentsType* getResource_Blocking(const std::string &itemID) {
                typename std::map<std::string, ore::resources::ResourceContainerEntry<ContentsType>>::iterator
                        entry = resourceMap.find(itemID);
                if(entry == resourceMap.end()) {
                    throw std::runtime_error("A requested resource named \"" + itemID + "\" of type \"" + std::string(typeid(ContentsType).name()) + "\" was not registered in advance!\nAll resources must be registered before they can be loaded.\nYou may be able to fix this by adding it to the game's resource list.");
                }

                // If it's unloaded, load it
                if(!entry->second.isLoaded) {
                    // Need to increment count for bookkeeping purposes
                    #pragma omp atomic
                    requiredItemsInProgress++;
                    loadEntry(itemID, true);
                }

                return entry->second.content;
            }
        };
    }
}
