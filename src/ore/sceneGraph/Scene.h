#pragma once

#include "SceneNode.h"
#include "ore/sceneGraph/nodes/ContainerNode.h"

namespace ore {
    struct Scene {
        ore::scene::ContainerNode rootNode;

        Scene() : rootNode("Root node") {}
    };
}