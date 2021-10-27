#pragma once

#include <ore/sceneGraph/nodes/ContainerNode.h>
#include <ore/resources/resourceTypes/material/Material.h>

#include <utility>

namespace ore {
    namespace scene {
    class MaterialNode : public ore::scene::ContainerNode {
    private:
        ore::resources::Material material;
    public:
        MaterialNode() : ore::scene::ContainerNode("Material Node") {}
        MaterialNode(ore::resources::Material material) : ore::scene::ContainerNode("Material Node"), material(std::move(material)) {}
    };
    }
}