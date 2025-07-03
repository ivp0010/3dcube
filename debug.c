#include "debug.h"
#include <stdio.h>

void APIENTRY myDebugCallback(GLenum source, GLenum type, GLuint id,
                              GLenum severity, GLsizei length,
                              const GLchar* message, const void* userParam) {
    fprintf(stderr, "GL DEBUG: %s\n", message);
}

