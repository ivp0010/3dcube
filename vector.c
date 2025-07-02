#include "vector.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

vec2 vec2_add(vec2* a, vec2* b)
{
	return (vec2){a->x + b->x, a->y + b->y};
}
vec2 vec2_sub(vec2* a, vec2* b)
{
	return (vec2){a->x - b->x, a->y - b->y};
}

float vec2_dot(vec2* a, vec2* b)
{
	return a->x * b->x + a->y * b->y;	
}

float vec2_length(vec2* v)
{
	return sqrtf(powf(v->x, 2) + powf(v->y, 2));
}


vec2 vec2_normalize(vec2* v)
{
	float len = vec2_length(v);
	return (len > 0.f) ? (vec2){v->x / len, v->y / len} : *v;
}


vec3 vec3_add(vec3* a, vec3* b)
{
	return (vec3){a->x + b->x, a->y + b->y, a->z + b->z};
}

vec3 vec3_sub(vec3* a, vec3* b)
{
	return (vec3){a->x - b->x, a->y - b->y, a->z - b->z};
}

float vec3_dot(vec3* a, vec3* b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

vec3 vec3_cross(vec3* a, vec3* b)
{
	vec3 product;
	product.x = a->y * b->z + b->y * a->z;
	product.y = a->x * b->z + b->x * a->z;
	product.z = a->x * b->y + b->x * a->y;
	return product;
}

float vec3_length(vec3* v)
{
	return sqrtf(powf(v->x, 2) + powf(v->y, 2) + powf(v->z, 2));
}

vec3 vec3_normalize(vec3* v)
{
	float len = vec3_length(v);
	return (len > 0.f) ? (vec3){v->x / len, v->y / len, v->z / len} : *v;
}


vec4 vec4_add(vec4* a, vec4* b)
{
	return  (vec4){a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w};
}

vec4 vec4_sub(vec4* a, vec4* b)
{
	return (vec4){a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w}; 
}

float vec4_dot(vec4* a, vec4* b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}

float vec4_length(vec4* v)
{
	return sqrtf(powf(v->x, 2) + powf(v->y, 2) + powf(v->z, 2) + powf(v->w, 2));
}

vec4 vec4_normalize(vec4* v)
{
	int len = vec4_length(v);
	return (len > 0.f) ? (vec4){v->x / len, v->y / len, v->z / len, v->w / len} : *v;
}

