#ifndef SHADER_H
#define SHADER_H

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "camera.h"
#include "matrix.h"
#include "vector.h"
#include <stdlib.h>



char* load_file(const char* filename);
GLuint compile_shader(const char* source, GLenum type);
GLuint link_program(GLuint vertexShader, GLuint fragmentShader);
GLuint shader_create(const char* vertexPath, const char* fragmentPath);
void shader_set_mat(GLuint shader_program, const char* name, const Mat* matrix);

#endif
