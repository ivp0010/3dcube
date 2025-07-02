#ifndef CAMERA_H
#define CAMERA_H
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "vector.h"
#include "matrix.h"

Mat mat_look(Mat* out, vec3* eye, vec3* center, vec3* up);








#endif
