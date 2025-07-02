#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "timer.h"

float getTime()
{
	return (float)glfwGetTime();
}
float getDeltaTime(float* prevTime)
{
	float currTime = getTime();
	float dt = currTime - *prevTime;
	*prevTime = currTime;
	return dt;
}

