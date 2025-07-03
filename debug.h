#ifndef DEBUG_H
#define DEBUG_H

#include <GLFW/glfw3.h>

void APIENTRY myDebugCallback(GLenum source, GLenum type, GLuint id,
                              GLenum severity, GLsizei length,
                              const GLchar* message, const void* userParam);

#endif
