#pragma once

#include <glad/glad.h>
#include <string>
#include <iostream>

namespace ore {
    namespace gl {
        // Checks for whether an OpenGL error occurred. If one did,
        // it prints out the error type and ID
        inline void printGLError(const std::string& file = "", unsigned int line = 0) {
            int errorID = glGetError();

            if(errorID != GL_NO_ERROR) {
                std::string errorString;

                switch(errorID) {
                    case GL_INVALID_ENUM:
                        errorString = "GL_INVALID_ENUM";
                        break;
                    case GL_INVALID_OPERATION:
                        errorString = "GL_INVALID_OPERATION";
                        break;
                    case GL_INVALID_FRAMEBUFFER_OPERATION:
                        errorString = "GL_INVALID_FRAMEBUFFER_OPERATION";
                        break;
                    case GL_OUT_OF_MEMORY:
                        errorString = "GL_OUT_OF_MEMORY";
                        break;
                    case GL_STACK_UNDERFLOW:
                        errorString = "GL_STACK_UNDERFLOW";
                        break;
                    case GL_STACK_OVERFLOW:
                        errorString = "GL_STACK_OVERFLOW";
                        break;
                    default:
                        errorString = "[Unknown error ID]";
                        break;
                }

                std::string locationString =
                        (!file.empty() ? " in file " + file : "") +
                                (line != 0 ? " on line " + std::to_string(line) : "");
                std::cerr << "An OpenGL error occurred" + locationString + " (" + std::to_string(errorID) + "): " + errorString + ".\n";
            }
        }
    }
}