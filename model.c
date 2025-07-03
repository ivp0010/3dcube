#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "camera.h"
#include "matrix.h"
#include "vector.h"
#include <stdlib.h>
#include "model.h"

void make_cube_model(Mat* model, float angle)
{
    Mat T, R, S, temp;
    makeTranslationMatrix(&T, 0.f, 0.f, -10.f);
    makeRotationMatrix(&R, angle);
    makeScalingMatrix(&S, 1.f, 1.f, 1.f);

    matrixMultiplcation(&temp, &R, &S);

    matrixMultiplcation(model, &T, &temp);
}
