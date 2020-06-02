#include "GeometryNode.h"

void ore::scene::GeometryNode::preRender(ore::RenderState &renderState) {

}

void ore::scene::GeometryNode::render(ore::RenderState &renderState) {

}

void ore::scene::GeometryNode::postRender(ore::RenderState &renderState) {

}

void ore::scene::GeometryNode::preUpdate(ore::RenderState &renderState) {
    CoordinateNode::preUpdate(renderState);
    modelMatrix = renderState.transformations.model;
}

void ore::scene::GeometryNode::postUpdate(ore::RenderState &renderState) {
    CoordinateNode::postUpdate(renderState);
}
