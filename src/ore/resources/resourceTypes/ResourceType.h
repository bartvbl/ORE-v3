#pragma once

#include <ore/utilities/filesystem.h>
#include <g3log/loglevels.hpp>
#include <g3log/g3log.hpp>

namespace ore {
    namespace resources {
        class ResourceType {
        protected:
            void* userdata = nullptr;
            std::string name;

            unsigned int inUseCount = 0;
            void registerInstanceCreation();
            void registerInstanceDestruction();
        public:
            virtual void load(const ore::filesystem::path &fileLocation) = 0;
            virtual bool requiresMainThread() = 0;
            virtual void completeLoadOnMainThread() = 0;
            virtual void destroy() = 0;
            void setName(std::string &name);
        };
    }
}