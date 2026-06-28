#include "defaultResources.h"

void ore::resources::enqueueDefaultResources(ResourceCache *cache) {
    cache->shaders.registerResource("default_plainTextureShader", ResourceLoadPriority::REQUIRED,
        "../res/builtin_shaders/plainTexture.shader", new ShaderResource());
    cache->shaders.registerResource("default_plainColourShader", ResourceLoadPriority::REQUIRED,
        "../res/builtin_shaders/plainColour.shader", new ShaderResource());
    cache->fonts.registerResource("default_font", ResourceLoadPriority::REQUIRED,
        "../res/builtin_fonts/Arial.ttf", new FontResource());
}
