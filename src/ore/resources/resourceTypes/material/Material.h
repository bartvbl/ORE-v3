#pragma once
#include <string>
#include <utility>
#include <ore/geom/vec3.h>
#include <ore/utilities/filesystem.h>
#include <iostream>
#include <ore/resources/resourceTypes/TextureResource.h>

namespace ore {
    namespace resources {
        struct Material {
            std::string name;
            ore::geom::vec3 ambientColour;
            ore::geom::vec3 diffuseColour;
            ore::geom::vec3 specularColour;
            ore::geom::vec3 emissionColour;
            float transparency = 1;
            std::string diffuseTexturePath;
            std::string normalMapTexturePath;
            ore::resources::TextureResource diffuseTexture;
            ore::resources::TextureResource normalMapTexture;

            Material(
                    std::string materialName,
                    ore::geom::vec3 materialAmbientColour = ore::geom::vec3(0, 0, 0),
                    ore::geom::vec3 materialDiffuseColour = ore::geom::vec3(1, 1, 1),
                    ore::geom::vec3 materialSpecularColour = ore::geom::vec3(1, 1, 1),
                    ore::geom::vec3 materialEmissionColour = ore::geom::vec3(0, 0, 0),
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
        };
    }
}