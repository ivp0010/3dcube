#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "camera.h"
#include "matrix.h"
#include "vector.h"
#include <stdlib.h>
#include "geoLoader.h"

void create_buffer(mesh* geo)
{
	glGenVertexArrays(1, &geo->vao);
	glBindVertexArray(geo->vao);
	glGenBuffers(1, &geo->ebo);
	glGenBuffers(1, &geo->vbo);

	glBindBuffer(GL_ARRAY_BUFFER, geo->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * geo->vertex_count, geo->verticies, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geo->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * geo->index_count, geo->indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(offsetof(vertex, normal)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(offsetof(vertex, texcoord)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
	
}

void render_mesh(mesh* geo, GLuint id)
{
	glUseProgram(id);
	glBindVertexArray(geo->vao);
	glDrawElements(GL_TRIANGLES, geo->index_count, GL_UNSIGNED_INT, 0);
}

void destroy_mesh(mesh* geo)
{
    glDeleteBuffers(1, &geo->vbo);
    glDeleteBuffers(1, &geo->ebo);
    glDeleteVertexArrays(1, &geo->vao);
}
