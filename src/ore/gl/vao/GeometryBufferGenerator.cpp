#include <glad/glad.h>

#include <ore/resources/resourceTypes/mesh/Mesh.h>
#include <stdexcept>
#include <ore/gl/shader/ShaderUniformIndex.h>
#include "GeometryBufferGenerator.h"

void augmentVAOWithTBNBuffers(unsigned int vaoID, const ore::resources::MeshGeometry &geometry, unsigned int drawMode) {
    std::vector<glm::vec3> T;
    std::vector<glm::vec3> B;

    T.resize(geometry.vertices.size());
    B.resize(geometry.vertices.size());

    for(unsigned int triangle = 0; triangle < geometry.indices.size() / 3; triangle++) {
        glm::vec3 vertex0 = geometry.vertices.at(3 * triangle + 0);
        glm::vec3 vertex1 = geometry.vertices.at(3 * triangle + 1);
        glm::vec3 vertex2 = geometry.vertices.at(3 * triangle + 2);

        glm::vec2 texCoord0 = geometry.textureCoordinates.at(3 * triangle + 0);
        glm::vec2 texCoord1 = geometry.textureCoordinates.at(3 * triangle + 1);
        glm::vec2 texCoord2 = geometry.textureCoordinates.at(3 * triangle + 2);

        glm::vec3 edge1 = vertex1 - vertex0;
        glm::vec3 edge2 = vertex2 - vertex0;
        glm::vec2 deltaUV1 = texCoord1 - texCoord0;
        glm::vec2 deltaUV2 = texCoord2 - texCoord0;

        float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

        glm::vec3 tangent;
        tangent.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
        tangent.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
        tangent.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
        tangent = glm::normalize(tangent);

        T.at(3 * triangle + 0) = tangent;
        T.at(3 * triangle + 1) = tangent;
        T.at(3 * triangle + 2) = tangent;

        glm::vec3 bitangent;
        bitangent.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
        bitangent.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
        bitangent.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
        bitangent = glm::normalize(bitangent);

        B.at(3 * triangle + 0) = bitangent;
        B.at(3 * triangle + 1) = bitangent;
        B.at(3 * triangle + 2) = bitangent;
    }

    glBindVertexArray(vaoID);

    unsigned int tangentBufferID;
    glGenBuffers(1, &tangentBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, tangentBufferID);
    glBufferData(GL_ARRAY_BUFFER, T.size() * sizeof(glm::vec3), T.data(), drawMode);
    glVertexAttribPointer(ore::gl::ShaderInputIndex::normalMapTangent, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(ore::gl::ShaderInputIndex::normalMapTangent);

    unsigned int bitangentBufferID;
    glGenBuffers(1, &bitangentBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bitangentBufferID);
    glBufferData(GL_ARRAY_BUFFER, B.size() * sizeof(glm::vec3), B.data(), drawMode);
    glVertexAttribPointer(ore::gl::ShaderInputIndex::normalMapBitangent, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(ore::gl::ShaderInputIndex::normalMapBitangent);
}


ore::gl::GeometryBuffer ore::gl::generateGeometryBuffer(const ore::resources::MeshGeometry &geometry, unsigned int drawMode) {
    ore::gl::GeometryBuffer buffer;
    updateGeometryBuffer(geometry, buffer, drawMode);
    return buffer;
}

ore::gl::GeometryBuffer ore::gl::createStreamingGeometryBuffer() {
    ore::resources::MeshGeometry geometry;
    geometry.vertices = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}};
    geometry.indices = {0, 1, 2, 0, 2, 3};
    geometry.hasNormals = false;
    geometry.hasTextures = false;
    geometry.hasNormalMap = false;

    ore::gl::GeometryBuffer buffer = generateGeometryBuffer(geometry, GL_STREAM_DRAW);

    return buffer;
}

void ore::gl::updateGeometryBuffer(const ore::resources::MeshGeometry &geometry, ore::gl::GeometryBuffer &buffer,
                              unsigned int drawMode) {

    if(drawMode == 0xFFFFFFFF) {
        drawMode = GL_STATIC_DRAW;
    }

    if(buffer.vaoID == 0xFFFFFFFF) {
        glGenVertexArrays(1, &buffer.vaoID);
    }
    glBindVertexArray(buffer.vaoID);

    if(buffer.vertexBufferID == 0xFFFFFFFF) {
        glGenBuffers(1, &buffer.vertexBufferID);
    }
    glBindBuffer(GL_ARRAY_BUFFER, buffer.vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, geometry.vertices.size() * sizeof(glm::vec3), geometry.vertices.data(), drawMode);
    glVertexAttribPointer(ore::gl::ShaderInputIndex::vertices, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(ore::gl::ShaderInputIndex::vertices);

    if(geometry.hasNormals) {
        if(buffer.normalBufferID == 0xFFFFFFFF) {
            glGenBuffers(1, &buffer.normalBufferID);
        }
        glBindBuffer(GL_ARRAY_BUFFER, buffer.normalBufferID);
        glBufferData(GL_ARRAY_BUFFER, geometry.normals.size() * sizeof(glm::vec3), geometry.normals.data(), drawMode);
        glVertexAttribPointer(ore::gl::ShaderInputIndex::normals, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(ore::gl::ShaderInputIndex::normals);
    } else if(buffer.normalBufferID != 0xFFFFFFFF) {
        glDisableVertexAttribArray(ore::gl::ShaderInputIndex::normals);
    }

    if(geometry.hasTextures) {
        if(buffer.textureBufferID == 0xFFFFFFFF) {
            glGenBuffers(1, &buffer.textureBufferID);
        }
        glBindBuffer(GL_ARRAY_BUFFER, buffer.textureBufferID);
        glBufferData(GL_ARRAY_BUFFER, geometry.textureCoordinates.size() * sizeof(glm::vec2), geometry.textureCoordinates.data(), drawMode);
        glVertexAttribPointer(ore::gl::ShaderInputIndex::texCoords, 2, GL_FLOAT, GL_TRUE, 2 * sizeof(float), nullptr);
        glEnableVertexAttribArray(ore::gl::ShaderInputIndex::texCoords);
    } else if(buffer.textureBufferID != 0xFFFFFFFF) {
        glDisableVertexAttribArray(ore::gl::ShaderInputIndex::texCoords);
    }

    if(geometry.hasNormalMap) {
        augmentVAOWithTBNBuffers(buffer.vaoID, geometry, drawMode);
    }

    if(buffer.indexBufferID == 0xFFFFFFFF) {
        glGenBuffers(1, &buffer.indexBufferID);
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, geometry.indices.size() * sizeof(unsigned int), geometry.indices.data(), drawMode);

    buffer.indexCount = geometry.indices.size();
}

