#pragma once

#include <string>
#include <unordered_map>
#include <ore/utilities/filesystem.h>

namespace ore {
    namespace resources {
        template<typename ContentsType>
        class ResourceContainer {
        private:
            std::unordered_map<std::string, ContentsType> resourceMap;
        public:
            void registerResource(std::string itemID, ore::filesystem::path fileLocation);
            bool loadNext();
            void evict(std::string itemID);

            const ContentsType* getResourceBlocking(std::string itemID);
        };
    }
}
