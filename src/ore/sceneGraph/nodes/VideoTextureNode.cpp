#include <ore/resources/resourceTypes/TextureResource.h>
#include <ore/gl/shapes/PrimitiveGenerator.h>
#include "VideoTextureNode.h"
#include "MaterialNode.h"
#include "GeometryNode.h"

void ore::scene::VideoTextureNode::preRender(ore::RenderState &state) {
    CoordinateNode::preRender(state);
}

void ore::scene::VideoTextureNode::render(ore::RenderState &renderState) {
    CoordinateNode::render(renderState);
}

ore::scene::VideoTextureNode::VideoTextureNode(std::filesystem::path videoFile) {
    /*ore::resources::Material* material = new ore::resources::Material();
    ore::scene::MaterialNode* materialNode = new ore::scene::MaterialNode(material);

    ore::resources::TextureResource* imageResource = world->resourceCache.textures.getResource_Blocking(graphicsObject.imageTextureResourceName);
    ore::resources::Texture imageTexture = imageResource->getInstance();
    material->diffuseTexture = imageTexture;

    ore::scene::GeometryNode* squarePlane = new ore::scene::GeometryNode(ore::gl::PrimitiveGenerator::generatePlaneBuffer());
    squarePlane->position = graphicsObject.position.position;
    squarePlane->rotation = graphicsObject.position.rotation;
    squarePlane->scale = glm::vec3(imageTexture.widthPixels, imageTexture.heightPixels, 1)
                         * graphicsObject.position.scale;

    graphicsImageMaterialNodes.push_back(materialNode);
    graphicsImageMaterials.push_back(material);
    graphicsImageGeometryNodes.push_back(squarePlane);
    materialNode->getChildren()->push_back(squarePlane);*/
}
