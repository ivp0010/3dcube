#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "camera.h"
#include "matrix.h"
#include "vector.h"
#include <stdlib.h>
#include "model.h"

void make_cube_model(Mat* model, float time, float rotation_speed)
{
	makeIdentityMatrix(model);
	Mat T, R, S;

	makeTranslationMatrix(&T, 0.f, 0.f, -5.f);
	float angle = time * rotation_speed;
	makeRotationMatrix(&R, angle);
	makeScalingMatrix(&S, 1.f, 1.f, 1.f);

	matrixMultiplcation(model, model, &S);
	matrixMultiplcation(model, model, &R);
	matrixMultiplcation(model, model, &T);

}
