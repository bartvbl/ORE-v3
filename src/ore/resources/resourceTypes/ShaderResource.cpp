#include <ore/gl/shader/ShaderLoader.h>
#include <iostream>
#include <thread>
#include "ShaderResource.h"

void ore::resources::ShaderResource::load(const ore::filesystem::path &fileLocation) {
    ore::filesystem::path containingDirectory = fileLocation.parent_path();
    std::string fileName = fileLocation.filename();
    // Remove the file extension
    size_t dotIndex = fileName.find('.');
    fileName = fileName.substr(0, dotIndex);
    shaderSources = ore::gl::loadShaderSources(containingDirectory, fileName);

}

bool ore::resources::ShaderResource::requiresMainThread() {
    return true;
}

void ore::resources::ShaderResource::completeLoadOnMainThread() {
    shader = ore::gl::createShader(shaderSources);
    delete shaderSources;
}

void ore::resources::ShaderResource::destroy() {
    shader.destroy();
}

ore::resources::Shader ore::resources::ShaderResource::getInstance() {
    return shader;
}