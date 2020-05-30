#pragma once

#include <string>

namespace ore {
    namespace gl {
        struct ShaderSource {
            std::string vertexShaderSource;
            std::string fragmentShaderSource;
            std::string geometryShaderSource;
            std::string computeShaderSource;
            std::string tesselationControlShaderSource;
            std::string tesselationEvaluationShaderSource;
        };
    }
}