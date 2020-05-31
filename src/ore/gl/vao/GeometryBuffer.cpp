#include <glad/glad.h>
#include "GeometryBuffer.h"

void ore::gl::GeometryBuffer::draw() {
    glBindVertexArray(vaoID);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
}
