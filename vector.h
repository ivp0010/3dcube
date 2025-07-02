#ifndef VECTOR_H
#define VECTOR_H
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct vector2
{
	float x, y;
}vec2;

typedef struct vector3
{
	float x, y, z;
}vec3;

typedef struct vector4
{
	float x, y, z, w;
}vec4;

vec2 vec2_add(vec2* a, vec2* b);
vec2 vec2_sub(vec2* a, vec2* b);
float vec2_dot(vec2* a, vec2* b);
float vec2_length(vec2* v);
vec2 vec2_normalize(vec2* v);
vec3 vec3_add(vec3* a, vec3* b);
vec3 vec3_sub(vec3* a, vec3* b);
float vec3_dot(vec3* a, vec3* b);
vec3 vec3_cross(vec3* a, vec3* b);
float vec3_length(vec3* v);
vec3 vec3_normalize(vec3* v);
vec4 vec4_add(vec4* a, vec4* b);
vec4 vec4_sub(vec4* a, vec4* b);
float vec4_dot(vec4* a, vec4* b);
float vec4_length(vec4* v);
vec4 vec4_normalize(vec4* v);



#endif
