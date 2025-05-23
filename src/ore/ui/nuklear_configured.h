#pragma once

// Nuklear requires that all files using it specify the exact same defines.
// This header should always be included, rather than the nuklear.h header directly for that reason.
#include <iostream>
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

#include "nuklear.h"
#include "nuklear_glfw_gl4.h"

#pragma GCC diagnostic pop