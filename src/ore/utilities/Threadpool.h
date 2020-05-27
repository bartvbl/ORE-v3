#pragma once

#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
#include <functional>

namespace ore {
    namespace utilities {
        class Threadpool {
        private:
            bool shutdownRequested = false;
            unsigned int activeThreadCount = 0;
            std::condition_variable poolBlocker;
            std::mutex poolBlockerMutex;
            std::vector<std::thread> threads;
            std::mutex workQueueLock;
            std::queue<std::function<void()>> workQueue;

            void threadLoop(int threadIndex) {
                #pragma omp atomic
                activeThreadCount++;

                while(!shutdownRequested) {
                    if(workQueue.size() == 0)
                    {
                        std::unique_lock<std::mutex> blockerLock(poolBlockerMutex);
                        poolBlocker.wait(blockerLock);
                    }
                    workQueueLock.lock();
                    if(workQueue.size() > 0) {
                        std::function<void()> workItem = workQueue.front();
                        workQueue.pop();
                        workQueueLock.unlock();

                        // execute job
                        workItem();
                    } else {
                        workQueueLock.unlock();
                    }
                }

                #pragma omp atomic
                activeThreadCount--;
            }

        public:
            const unsigned int threadCount;

            Threadpool(unsigned int count) : threadCount(count) {
                threads.reserve(count);
                for(int i = 0; i < count; i++) {
                    threads.push_back(std::move(std::thread([this, i] { this->threadLoop(i); })));
                }
            }

            void enqueue(std::function<void()> &workItem) {
                workQueueLock.lock();
                workQueue.push(workItem);
                workQueueLock.unlock();

                // Because of possible race conditions, we wake up all threads
                poolBlocker.notify_all();
            }

            void shutdown() {
                shutdownRequested = true;
                while(activeThreadCount > 0) {
                    // ensure no race conditions by continuously waking up all threads
                    poolBlocker.notify_all();
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                }

                // Avoid destructor complaints
                for(int i = 0; i < threads.size(); i++) {
                    // insert dark side joke here
                    if(threads.at(i).joinable()) {
                        threads.at(i).join();
                    }
                }
            }
        };
    }
}
