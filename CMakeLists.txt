#
# Specify minimum CMake version and project name
#
cmake_minimum_required (VERSION 3.8)
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


if(APPLE)
    if(CMAKE_C_COMPILER_ID MATCHES "Clang\$")
        set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp")
        set(OpenMP_C_LIB_NAMES "omp")
        set(OpenMP_omp_LIBRARY omp)
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang\$")
        set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp")
        set(OpenMP_CXX_LIB_NAMES "omp")
        set(OpenMP_omp_LIBRARY omp)
    endif()

endif()
find_package(OpenMP)

#
# GLFW options
#
option (GLFW_INSTALL OFF)
option (GLFW_BUILD_DOCS OFF)
option (GLFW_BUILD_EXAMPLES OFF)
option (GLFW_BUILD_TESTS OFF)
find_package(glfw3 REQUIRED)

add_subdirectory(lib/g3log g3log)

find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})

# Makes Jolt about 8% slower but makes simulation completely deterministic no matter where the code is run
set(CROSS_PLATFORM_DETERMINISTIC ON)
set(BUILD_SHARED_LIBS OFF)
set(OVERRIDE_CXX_FLAGS OFF)
set(ENABLE_ALL_WARNINGS OFF)
#add_definitions(-DJPH_ENABLE_ASSERTS -DJPH_DEBUG_RENDERER)
add_subdirectory(lib/JoltPhysics-5.1.0/Build joltPhysics)

find_package(PkgConfig)
#pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)

add_subdirectory(lib/miniaudio-0.11.22)

#find_package(PkgConfig REQUIRED)
#pkg_search_module(gstreamer REQUIRED IMPORTED_TARGET gstreamer-1.0>=1.4)
#pkg_search_module(gstreamer-sdp REQUIRED IMPORTED_TARGET gstreamer-sdp-1.0>=1.4)
#pkg_search_module(gstreamer-app REQUIRED IMPORTED_TARGET gstreamer-app-1.0>=1.4)
#pkg_search_module(gstreamer-video REQUIRED IMPORTED_TARGET gstreamer-video-1.0>=1.4)

#
# Set include paths
#
include_directories (
    src/
    lib/glad/include/
    lib/glfw/include/
    lib/glm/
    lib/stb_image/
    lib/fast_obj/
    lib/json/
    lib/g3log/src/
    lib/nuklear
    lib/JoltPhysics-5.1.0
    ${GLIB_INCLUDE_DIRS}
    ${GSTREAMER_INCLUDE_DIRS}
)

#
# Add files
#
file (GLOB         LIBRARY_SOURCES lib/glad/src/glad.c
                                   lib/fast_obj/fast_obj.c)
file (GLOB_RECURSE PROJECT_HEADERS src/*.hpp
                                   src/*.h)
file (GLOB_RECURSE PROJECT_SOURCES src/*.cpp
                                   src/*.cxx
                                   src/*.cc
                                   src/*.c)

add_definitions(-DGLFW_INCLUDE_NONE)
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${LIBRARY_SOURCES})


  target_link_libraries (${PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${GLAD_LIBRARIES} OpenMP::OpenMP_CXX g3log Jolt miniaudio ${FREETYPE_LIBRARIES} ${GSTREAMER_LIBRARIES}
#          PkgConfig::gstreamer
#          PkgConfig::gstreamer-sdp
#          PkgConfig::gstreamer-app
#          PkgConfig::gstreamer-video
  )

set_property(TARGET ${PROJECT_NAME} PROPERTY CUDA_ARCHITECTURES 52 60 61 70 75 86)
