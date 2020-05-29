#include "Material.h"

void ore::resources::Material::load() {
    if(!diffuseTexturePath.empty()) {
        diffuseTexture.load(diffuseTexturePath);
    }
    if(!normalMapTexturePath.empty()) {
        normalMapTexture.load(normalMapTexturePath);
    }
}

void ore::resources::Material::completeOnMainThread() {
    if(!diffuseTexturePath.empty()) {
        diffuseTexture.completeLoadOnMainThread();
    }
    if(!normalMapTexturePath.empty()) {
        normalMapTexture.completeLoadOnMainThread();
    }
}
