#pragma once

#include <string>
#include <map>
#include <ore/utilities/filesystem.h>
#include <ore/resources/ResourceLoadPriority.h>
#include <cassert>
#include <iostream>
#include <queue>

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

            void loadEntry(const std::string &entryID) {
                ore::resources::ResourceContainerEntry<ContentsType>* entry = &resourceMap.find(entryID);
                ore::resources::ResourceType* resourceType = entry->content;
                resourceType->load(entry->fileLocation);
                if(resourceType->requiresMainThread()) {
                    mainThreadCompletionQueue.push(entryID);
                } else {
                    entry->isLoaded = true;
                }
            }

            void runMainThreadJobs() {
                while(!mainThreadCompletionQueue.empty()) {
                    std::string nextEntry = mainThreadCompletionQueue.front();
                    mainThreadCompletionQueue.pop();
                    ore::resources::ResourceContainerEntry<ContentsType>* entry = &resourceMap.find(entryID);
                    ore::resources::ResourceType* resourceType = entry->content;
                    resourceType->completeLoadOnMainThread();
                    entry->isLoaded = true;
                }
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

        public:
            bool loadNext(ore::resources::ResourceLoadPriority threshold) {
                if(threshold == ore::resources::ResourceLoadPriority::REQUIRED &&
                   !requiredLoadingQueue.empty()) {
                    std::string nextEntry = requiredLoadingQueue.front();
                    requiredLoadingQueue.pop();
                    loadEntry(nextEntry);
                    return true;
                }
                if((threshold == ore::resources::ResourceLoadPriority::STREAMING ||
                    threshold == ore::resources::ResourceLoadPriority::REQUIRED) &&
                    !streamLoadingQueue.empty()) {
                    std::string nextEntry = streamLoadingQueue.front();
                    streamLoadingQueue.pop();
                    loadEntry(nextEntry);
                    return true;
                }
                return false;
            }

            void registerResource(std::string itemID, ore::resources::ResourceLoadPriority priority, ore::filesystem::path fileLocation) {
                std::cout << "Registering " << itemID << std::endl;
                ore::resources::ResourceContainerEntry<ContentsType> entry;
                entry.fileLocation = fileLocation;
                entry.priority = priority;
                if(this->resourceMap.find(itemID) == this->resourceMap.end()) {
                    this->resourceMap[itemID] = entry;
                    if(priority == ore::resources::ResourceLoadPriority::REQUIRED) {
                        requiredLoadingQueue.emplace(itemID);
                    }
                    if(priority == ore::resources::ResourceLoadPriority::STREAMING) {
                        streamLoadingQueue.emplace(itemID);
                    }
                }
            }

            void evict(const std::string &itemID) {

            }

            ContentsType* getResource_Blocking(const std::string &itemID) {

                return nullptr;
            }
        };
    }
}
