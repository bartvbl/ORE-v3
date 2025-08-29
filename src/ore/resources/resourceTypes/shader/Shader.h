#pragma once
#include <string>

namespace ore {
    namespace resources {
        class Shader {
        public:
            unsigned int programID = 0;
            std::string name = "Unnamed shader";
        public:
            Shader(unsigned int shaderProgramID, const std::string& _name) : programID(shaderProgramID), name{_name} {}
            Shader() = default;
            void use();
            unsigned int get();
            void setUniform(unsigned int ID, float* matrix);
            void setUniform(unsigned int ID, float x, float y, float z, float w);
            void destroy();
        };
    }
}