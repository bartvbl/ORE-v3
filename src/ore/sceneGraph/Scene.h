#pragma once

#include "SceneNode.h"
#include "ContainerNode.h"

namespace ore {
    struct Scene {
        ore::ContainerNode rootNode;

        Scene() : rootNode("Root node") {}
    };
}