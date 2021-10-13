#include <iostream>
#include <g3log/logworker.hpp>
#include "Logger.h"

static std::unique_ptr<g3::LogWorker> worker;
static std::unique_ptr<g3::FileSinkHandle> handle;

void ore::Logger::init() {
    worker = g3::LogWorker::createLogWorker();
    handle = worker->addDefaultLogger("ORE", "log/");
    g3::initializeLogging(worker.get());
}
