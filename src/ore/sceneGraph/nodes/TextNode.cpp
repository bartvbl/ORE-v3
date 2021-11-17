#include "TextNode.h"
#include <ore/gl/shader/ShaderUniformIndex.h>
#include <utility>
#include <iostream>

void ore::scene::TextNode::render(ore::RenderState &renderState) {
    if(textToShow.empty()) {
        return;
    }

    ore::gl::ShadingConfiguration previousConfiguration = renderState.shading;
    renderState.shading.enableLighting = false;
    renderState.shading.enableShadows = false;
    renderState.shading.enableTexturing = true;

    ore::scene::GeometryNode::preRender(renderState);

    // Enable the font texture
    renderState.uniforms.setTexture(ore::gl::ShaderUniformIndex::diffuseTextureID, font->textureMap);

    ore::scene::GeometryNode::drawBuffer();

    renderState.shading = previousConfiguration;
    ore::scene::GeometryNode::postRender(renderState);
}

void ore::scene::TextNode::setText(std::string text, unsigned int size) {
    if(!this->textToShow.empty()) {
        this->buffer.destroy();
    }

    textToShow = text;

    if(text.empty()) {
        return;
    }

    this->buffer = font->createRenderableText(text, size);
    this->indexCount = buffer.indexCount;
}
