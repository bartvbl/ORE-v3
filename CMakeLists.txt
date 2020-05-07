#
# Specify minimum CMake version and project name
#
cmake_minimum_required (VERSION 3.0)
project (ore)

#
# CMake setup
#
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set (CMAKE_VERBOSE_MAKEFILE 0) # 1 should be used for debugging
set (CMAKE_SUPPRESS_REGENERATION TRUE) # Suppresses ZERO_CHECK
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++17")
  if(NOT WIN32)
    set(GLAD_LIBRARIES dl)
  endif()
endif()

#
# GLFW options
#
option (GLFW_INSTALL OFF)
option (GLFW_BUILD_DOCS OFF)
option (GLFW_BUILD_EXAMPLES OFF)
option (GLFW_BUILD_TESTS OFF)
add_subdirectory (lib/glfw)

#
# Set include paths
#
include_directories (src/
                     lib/glad/include/
                     lib/glfw/include/
                     lib/glm/
                     lib/stb/)

#
# Add files
#
file (GLOB         LIBRARY_SOURCES lib/glad/src/glad.c)
file (GLOB_RECURSE PROJECT_HEADERS src/*.hpp
                                   src/*.h)
file (GLOB_RECURSE PROJECT_SOURCES src/*.cpp
                                   src/*.cxx
                                   src/*.cc
                                   src/*.c)

add_definitions(-DGLFW_INCLUDE_NONE)
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${LIBRARY_SOURCES})
target_link_libraries (${PROJECT_NAME} glfw stdc++fs ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})