#include "TextNode.h"

#include <utility>

void ore::scene::TextNode::render(ore::RenderState &renderState) {
    ore::gl::ShadingConfiguration previousConfiguration = renderState.shading;
    renderState.shading.enableLighting = false;
    renderState.shading.enableShadows = false;
    renderState.shading.enableTexturing = true;

    ore::scene::GeometryNode::preRender(renderState);

    font.drawText(textToShow, fontSize, position);

    renderState.shading = previousConfiguration;
    ore::scene::GeometryNode::postRender(renderState);
}

void ore::scene::TextNode::setText(std::string text) {
    this->textToShow = std::move(text);
}

void ore::scene::TextNode::setTextSize(unsigned int size) {
    this->fontSize = size;
}
