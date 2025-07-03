#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "camera.h"
#include "matrix.h"
#include "vector.h"
#include <stdlib.h>
#include "geoLoader.h"

void load_geometry(mesh* geo)
{
    static vertex cubeVertices[] = {

        {{-1, -1,  1}, { 0,  0,  1}, {0, 0}},
        {{ 1, -1,  1}, { 0,  0,  1}, {1, 0}},
        {{ 1,  1,  1}, { 0,  0,  1}, {1, 1}},
        {{-1,  1,  1}, { 0,  0,  1}, {0, 1}},

        {{-1, -1, -1}, { 0,  0, -1}, {0, 0}},
        {{ 1, -1, -1}, { 0,  0, -1}, {1, 0}},
        {{ 1,  1, -1}, { 0,  0, -1}, {1, 1}},
        {{-1,  1, -1}, { 0,  0, -1}, {0, 1}},

        {{-1, -1, -1}, {-1,  0,  0}, {0, 0}},
        {{-1, -1,  1}, {-1,  0,  0}, {1, 0}},
        {{-1,  1,  1}, {-1,  0,  0}, {1, 1}},
        {{-1,  1, -1}, {-1,  0,  0}, {0, 1}},

        {{ 1, -1, -1}, { 1,  0,  0}, {0, 0}},
        {{ 1, -1,  1}, { 1,  0,  0}, {1, 0}},
        {{ 1,  1,  1}, { 1,  0,  0}, {1, 1}},
        {{ 1,  1, -1}, { 1,  0,  0}, {0, 1}},

        {{-1,  1, -1}, { 0,  1,  0}, {0, 0}},
        {{ 1,  1, -1}, { 0,  1,  0}, {1, 0}},
        {{ 1,  1,  1}, { 0,  1,  0}, {1, 1}},
        {{-1,  1,  1}, { 0,  1,  0}, {0, 1}},

        {{-1, -1, -1}, { 0, -1,  0}, {0, 0}},
        {{ 1, -1, -1}, { 0, -1,  0}, {1, 0}},
        {{ 1, -1,  1}, { 0, -1,  0}, {1, 1}},
        {{-1, -1,  1}, { 0, -1,  0}, {0, 1}},
    };

   
   static unsigned int cubeIndices[] = {
        0, 1, 2,  2, 3, 0,        
        4, 5, 6,  6, 7, 4,         
        8, 9,10, 10,11, 8,         
        12,13,14, 14,15,12,        
        16,17,18, 18,19,16,        
        20,21,22, 22,23,20         
    };

    geo->vertex_count = sizeof(cubeVertices) / sizeof(vertex);
    geo->index_count = sizeof(cubeIndices) / sizeof(unsigned int);

    geo->verticies = malloc(sizeof(cubeVertices));
    geo->indices = malloc(sizeof(cubeIndices));

    memcpy(geo->verticies, cubeVertices, sizeof(cubeVertices));
    memcpy(geo->indices, cubeIndices, sizeof(cubeIndices));

    printf("VAO: %u | VBO: %u | EBO: %u | Vertices: %zu | Indices: %zu\n",
           geo->vao, geo->vbo, geo->ebo, geo->vertex_count, geo->index_count);
}


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
		printf("VAO: %u | VBO: %u | EBO: %u | Vertices: %zu | Indices: %zu\n",
       geo->vao, geo->vbo, geo->ebo, geo->vertex_count, geo->index_count);

}

void render_mesh(mesh* geo, GLuint id)
{
	glBindVertexArray(geo->vao);
	glDrawElements(GL_TRIANGLES, geo->index_count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	printf("Rendering mesh with %d vertices\n", geo->vertex_count);

}

void destroy_mesh(mesh* geo)
{
    glDeleteBuffers(1, &geo->vbo);
    glDeleteBuffers(1, &geo->ebo);
    glDeleteVertexArrays(1, &geo->vao);
}


