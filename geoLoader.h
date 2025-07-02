#ifndef GEOLOADER_H
#define GEOLOADER_H
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "camera.h"
#include "matrix.h"
#include "vector.h"
#include <stdlib.h>



typedef struct
{
	float position[3];
	float normal[3];
	float texcoord[2];
}vertex;

typedef struct
{
	vertex* verticies;
	unsigned int* indices;
	size_t vertex_count;
	size_t index_count;
	GLuint vao, vbo, ebo;
}mesh;

void create_buffer(mesh* geo);
void destroy_mesh(mesh* geo);
void render_mesh(mesh* geo, GLuint id);

#endif
