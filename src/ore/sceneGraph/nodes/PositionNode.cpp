#include "PositionNode.h"

void ore::scene::PositionNode::render(ore::RenderState &state) {
    CoordinateNode::preRender(state);
    CoordinateNode::render(state);
    CoordinateNode::postRender(state);
}
