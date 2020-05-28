#include <glad/glad.h>

#include <ore/resources/resourceTypes/mesh/Mesh.h>
#include <stdexcept>
#include "GeometryBufferGenerator.h"
/*
void augmentVAOWithTBNBuffers(unsigned int vaoID, ore::resources::Mesh &mesh) {
    std::vector<glm::vec3> T;
    std::vector<glm::vec3> B;

    T.resize(mesh.geometry->vertices.size());
    B.resize(mesh.geometry->vertices.size());

    for(unsigned int triangle = 0; triangle < mesh.geometry->indices.size() / 3; triangle++) {
        glm::vec3 vertex0 = mesh.geometry->vertices.at(3 * triangle + 0);
        glm::vec3 vertex1 = mesh.geometry->vertices.at(3 * triangle + 1);
        glm::vec3 vertex2 = mesh.geometry->vertices.at(3 * triangle + 2);

        glm::vec2 texCoord0 = mesh.geometry->textureCoordinates.at(3 * triangle + 0);
        glm::vec2 texCoord1 = mesh.geometry->textureCoordinates.at(3 * triangle + 1);
        glm::vec2 texCoord2 = mesh.geometry->textureCoordinates.at(3 * triangle + 2);

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
    glBufferData(GL_ARRAY_BUFFER, T.size() * sizeof(glm::vec3), T.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(5, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(5);

    unsigned int bitangentBufferID;
    glGenBuffers(1, &bitangentBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bitangentBufferID);
    glBufferData(GL_ARRAY_BUFFER, B.size() * sizeof(glm::vec3), B.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(6, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(6);
}
 */

ore::gl::GeometryBuffer generateTexturedNormalBuffer(ore::resources::Mesh &mesh) {
    ore::gl::GeometryBuffer buffer;

    glGenVertexArrays(1, &buffer.vaoID);
    glBindVertexArray(buffer.vaoID);

    glGenBuffers(1, &buffer.vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, buffer.vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, mesh.geometry->vertexCount * 3 * sizeof(float), mesh.geometry->vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    if(mesh.geometry->hasNormals) {
        glGenBuffers(1, &buffer.normalBufferID);
        glBindBuffer(GL_ARRAY_BUFFER, buffer.normalBufferID);
        glBufferData(GL_ARRAY_BUFFER, mesh.geometry->vertexCount * 3 * sizeof(float), mesh.geometry->normals, GL_STATIC_DRAW);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(1);
    }

    if(mesh.geometry->hasTextures) {
        glGenBuffers(1, &buffer.textureBufferID);
        glBindBuffer(GL_ARRAY_BUFFER, buffer.textureBufferID);
        glBufferData(GL_ARRAY_BUFFER, mesh.geometry->vertexCount * 2 * sizeof(float), mesh.geometry->textureCoordinates, GL_STATIC_DRAW);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, 2 * sizeof(float), nullptr);
        glEnableVertexAttribArray(2);
    }

    if(mesh.geometry->hasNormalMap) {
        throw std::runtime_error("Normal map support is disabled!");
        //augmentVAOWithTBNBuffers(buffer.vaoID, mesh);
    }

    glGenBuffers(1, &buffer.indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.geometry->indexCount * sizeof(unsigned int), mesh.geometry->indices, GL_STATIC_DRAW);

    return buffer;
}

