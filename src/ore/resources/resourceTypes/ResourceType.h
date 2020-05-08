#pragma once

namespace ore {
    namespace resources {
        class ResourceType {
            virtual void load() = 0;
            virtual bool requiresMainThread() = 0;
            virtual void completeLoadOnMainThread() = 0;
        };
    }
}