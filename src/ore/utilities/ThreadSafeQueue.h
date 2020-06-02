#pragma once

#include <queue>
#include <mutex>

namespace ore {
    namespace utilities {
        template<typename ContentsType>
        class ThreadSafeQueue {
        private:
            std::queue<ContentsType> queue;
            std::mutex queueMutex;
        public:
            void put(const ContentsType &contents);
            ContentsType get();
            size_t size();
            bool empty();
        };
    }
}