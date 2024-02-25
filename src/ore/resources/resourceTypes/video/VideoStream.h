#pragma once
#include <filesystem>

namespace ore::resources {
    class VideoStream {
        std::filesystem::path sourceFile;
    public:
        explicit VideoStream(std::filesystem::path inPath) : sourceFile{std::move(inPath)} {}
        std::filesystem::path getPath();
    };
}
