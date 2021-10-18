#include <iostream>
#include <g3log/logworker.hpp>
#include "filesystem.h"
#include "Logger.h"

static std::unique_ptr<g3::LogWorker> worker;
static std::unique_ptr<g3::FileSinkHandle> handle;

void ore::Logger::init() {
    const std::string loggingDirectory = "log/";
    if(!ore::filesystem::exists(ore::filesystem::path(loggingDirectory))) {
        ore::filesystem::create_directories(ore::filesystem::path(loggingDirectory).parent_path());
    }
    worker = g3::LogWorker::createLogWorker();
    handle = worker->addDefaultLogger("ORE", "log/");
    g3::initializeLogging(worker.get());
}
