#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "camera.h"
#include "matrix.h"
#include "vector.h"

Mat mat_look(Mat* out, vec3* eye, vec3* center, vec3* up)
{
	vec3 temp = vec3_sub(center, eye);
	vec3 forward = vec3_normalize(&temp);
	temp = vec3_cross(&forward, up);
	vec3 right = vec3_normalize(&temp);
	vec3 upN = vec3_cross(&right , &forward);


	out->arr[0] = right.x;
	out->arr[1] = upN.x; 
	out->arr[2] = -forward.x; 
	out->arr[3] = 0.f;

	out->arr[4] = right.y;
	out->arr[5] = upN.y;
	out->arr[6] = -forward.y;
	out->arr[7] = 0.f;

	out->arr[8] = right.z;
	out->arr[9] = upN.z;
	out->arr[10] = -forward.z;
	out->arr[11] = 0.f;

	out->arr[12] = -vec3_dot(&right, eye);
	out->arr[13] = -vec3_dot(&upN, eye);
	out->arr[14] = -vec3_dot(&forward, eye);
	out->arr[15] = 1.f;
		
	
	return *out;
}

