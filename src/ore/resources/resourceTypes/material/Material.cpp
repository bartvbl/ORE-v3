#include "Material.h"

void ore::resources::Material::load() {
    if(!diffuseTexturePath.empty()) {
        diffuseTextureResource.load(diffuseTexturePath);
    }
    if(!normalMapTexturePath.empty()) {
        normalMapTextureResource.load(normalMapTexturePath);
    }
}

void ore::resources::Material::completeOnMainThread() {
    if(!diffuseTexturePath.empty()) {
        diffuseTextureResource.completeLoadOnMainThread();
        diffuseTexture = diffuseTextureResource.getInstance();
    }
    if(!normalMapTexturePath.empty()) {
        normalMapTextureResource.completeLoadOnMainThread();
        normalMapTexture = normalMapTextureResource.getInstance();
    }
}

bool ore::resources::Material::hasDiffuseTexture() {
    return diffuseTexture.id > 0;
}

bool ore::resources::Material::hasNormalMap() {
    return normalMapTexture.id > 0;
}
