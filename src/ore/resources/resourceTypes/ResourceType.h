#pragma once

#include <ore/utilities/filesystem.h>

namespace ore {
    namespace resources {
        class ResourceType {
        public:
            virtual void load(const ore::filesystem::path &fileLocation) = 0;
            virtual bool requiresMainThread() = 0;
            virtual void completeLoadOnMainThread() = 0;
        };
    }
}