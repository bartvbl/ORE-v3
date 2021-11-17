#pragma once

#include "CoordinateNode.h"
#include <ore/gl/font/Font.h>
#include <ore/sceneGraph/nodes/GeometryNode.h>

namespace ore {
    namespace scene {
        class TextNode : public ore::scene::GeometryNode {
        private:
            ore::gl::Font* font;
            std::string textToShow = "";
            unsigned int fontSize = 16;
        public:
            TextNode() : ore::scene::GeometryNode("Text Node") {}
            TextNode(ore::gl::Font* font) : ore::scene::GeometryNode("Text Node"), font(font) {}
            void setText(std::string text, unsigned int size);
            void render(RenderState &renderState) override;
        };
    }
}