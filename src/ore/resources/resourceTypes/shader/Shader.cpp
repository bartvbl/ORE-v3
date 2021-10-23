#include <glad/glad.h>
#include <iostream>
#include "Shader.h"

void ore::resources::Shader::use() {
    glUseProgram(programID);
}

void ore::resources::Shader::destroy() {
    glDeleteProgram(programID);
}

unsigned int ore::resources::Shader::get() {
    return programID;
}

void ore::resources::Shader::setUniform(unsigned int ID, float *matrix) {
    glUniformMatrix4fv(ID, 1, GL_FALSE, matrix);
}

void ore::resources::Shader::setUniform(unsigned int ID, float x, float y, float z, float w) {
    glUniform4f(ID, x, y, z, w);
}
