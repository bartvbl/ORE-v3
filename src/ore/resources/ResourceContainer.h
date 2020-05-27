#pragma once

#include <string>
#include <map>
#include <ore/utilities/filesystem.h>
#include <ore/resources/ResourceLoadPriority.h>
#include <cassert>
#include <iostream>
#include <queue>
#include <mutex>

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

            void loadEntry(const std::string &entryID) {
                std::cout << "Loading entry: " + entryID + "\n" << std::flush;
                typename std::map<std::string, ore::resources::ResourceContainerEntry<ContentsType>>::iterator
                    entry = resourceMap.find(entryID);
                ore::resources::ResourceType* resourceType = entry->second.content;
                // Some order of events exist where a resource is loaded before a loading
                // thread can get to it. So we do a check here just in case.
                if(entry->second.isLoaded) {
                    return;
                }
                resourceType->load(entry->second.fileLocation);
                if(resourceType->requiresMainThread()) {
                    mainThreadQueueMutex.lock();
                    mainThreadCompletionQueue.push(entryID);
                    mainThreadQueueMutex.unlock();
                } else {
                    entry->second.isLoaded = true;
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
                }
                mainThreadQueueMutex.unlock();
            }

            unsigned int getEnqueuedItemCount(ore::resources::ResourceLoadPriority threshold) {
                unsigned int enqueuedItemCount = 0;
                if(threshold == ore::resources::ResourceLoadPriority::REQUIRED) {
                    enqueuedItemCount += requiredLoadingQueue.size();
                }
                if((threshold == ore::resources::ResourceLoadPriority::STREAMING ||
                    threshold == ore::resources::ResourceLoadPriority::REQUIRED)) {
                    enqueuedItemCount += streamLoadingQueue.size();
                }
                return enqueuedItemCount;
            }

            bool loadNext(ore::resources::ResourceLoadPriority threshold) {
                loadingQueueMutex.lock();
                if(threshold == ore::resources::ResourceLoadPriority::REQUIRED &&
                   !requiredLoadingQueue.empty()) {
                    std::string nextEntry = requiredLoadingQueue.front();
                    requiredLoadingQueue.pop();
                    loadingQueueMutex.unlock();
                    loadEntry(nextEntry);
                    return true;
                }
                if((threshold == ore::resources::ResourceLoadPriority::STREAMING ||
                    threshold == ore::resources::ResourceLoadPriority::REQUIRED) &&
                   !streamLoadingQueue.empty()) {
                    std::string nextEntry = streamLoadingQueue.front();
                    streamLoadingQueue.pop();
                    loadingQueueMutex.unlock();
                    loadEntry(nextEntry);
                    return true;
                }
                loadingQueueMutex.unlock();
                return false;
            }

            void evict(const std::string &itemID) {

            }

        public:
            void registerResource(std::string itemID, ore::resources::ResourceLoadPriority priority, ore::filesystem::path fileLocation) {
                std::cout << "Registering " << itemID << std::endl;
                ore::resources::ResourceContainerEntry<ContentsType> entry;
                entry.fileLocation = fileLocation;
                entry.priority = priority;
                entry.content = new ContentsType();
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

                return nullptr;
            }
        };
    }
}
