#pragma once

#include <glad/glad.h>
#include <cassert>
#include <fstream>
#include <memory>
#include <string>
#include <ore/resources/resourceTypes/shader/Shader.h>
#include "ShaderSource.h"
#include <ore/utilities/filesystem.h>

namespace ore
{
    namespace gl {
        ore::gl::ShaderSource* loadShaderSources(const ore::filesystem::path& directory, const std::string& fileName);
        ore::resources::Shader createShader(ore::gl::ShaderSource* source, const std::string& name);
    }
}