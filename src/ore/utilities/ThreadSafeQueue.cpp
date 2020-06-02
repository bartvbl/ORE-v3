#include "ThreadSafeQueue.h"

template<typename ContentsType>
void ore::utilities::ThreadSafeQueue<ContentsType>::put(const ContentsType &entry) {
    std::unique_lock lock(queueMutex);
    queue.push(entry);
}

template<typename ContentsType>
ContentsType ore::utilities::ThreadSafeQueue<ContentsType>::get() {
    std::unique_lock lock(queueMutex);
    ContentsType* entry = queue.front();
    queue.pop();
    return entry;
}

template<typename ContentsType>
size_t ore::utilities::ThreadSafeQueue<ContentsType>::size() {
    return queue.size();
}

template<typename ContentsType>
bool ore::utilities::ThreadSafeQueue<ContentsType>::empty() {
    return queue.empty();
}
