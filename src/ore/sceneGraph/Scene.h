#pragma once

#include "SceneNode.h"
#include "ore/sceneGraph/nodes/ContainerNode.h"
#include "ore/ui/GUIRootNode.h"

namespace ore {
    struct Scene {
        ore::scene::ContainerNode rootNode;
        ore::GUIRootNode guiRootNode;

        Scene() : rootNode("Root node") {}
    };
}