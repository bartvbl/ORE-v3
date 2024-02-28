#pragma once
#include <string>
#include <utility>
#include <ore/geom/vec4.h>
#include <ore/utilities/filesystem.h>
#include <iostream>
#include <ore/resources/resourceTypes/TextureResource.h>

namespace ore {
    namespace resources {
        class Material {
        private:
            ore::resources::TextureResource diffuseTextureResource;
            ore::resources::TextureResource normalMapTextureResource;
        public:

            std::string name;
            ore::geom::vec4 ambientColour;
            ore::geom::vec4 diffuseColour;
            ore::geom::vec4 specularColour;
            ore::geom::vec4 emissionColour;
            float transparency = 1;
            std::string diffuseTexturePath;
            std::string normalMapTexturePath;
            ore::resources::Texture diffuseTexture;
            ore::resources::Texture normalMapTexture;

            Material(
                    std::string materialName,
                    ore::geom::vec4 materialAmbientColour = ore::geom::vec4(0, 0, 0, 1),
                    ore::geom::vec4 materialDiffuseColour = ore::geom::vec4(1, 1, 1, 1),
                    ore::geom::vec4 materialSpecularColour = ore::geom::vec4(1, 1, 1, 1),
                    ore::geom::vec4 materialEmissionColour = ore::geom::vec4(0, 0, 0, 1),
                    float materialTransparency = 1.0,
                    std::string materialDiffuseTexturePath = "",
                    std::string materialNormalMapTexturePath = "")
                    : name(std::move(materialName)),
                      ambientColour(materialAmbientColour),
                      diffuseColour(materialDiffuseColour),
                      specularColour(materialSpecularColour),
                      emissionColour(materialEmissionColour),
                      transparency(materialTransparency),
                      diffuseTexturePath(std::move(materialDiffuseTexturePath)),
                      normalMapTexturePath(std::move(materialNormalMapTexturePath)) {}
            Material() = default;

            void load();
            void completeOnMainThread();

            bool hasDiffuseTexture();

            bool hasNormalMap();
        };
    }
}