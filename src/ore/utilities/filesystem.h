#pragma once

#ifdef _MSC_VER
#include <filesystem>
#else
#include <experimental/filesystem>
#endif

namespace ore {
#ifdef _MSC_VER
    namespace filesystem = std::filesystem;
#else
    namespace filesystem = std::experimental::filesystem;
#endif
}
