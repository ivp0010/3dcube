#ifndef MATRIX_H
#define MATRIX_H
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct matrix_4x4
{
	float arr[16];

}Mat;

void makeRotationMatrix(Mat* rotMat, float angle);
void makeTransformationMatrix(Mat* tranMat, float x, float y, float z);
void makePerspectiveMatrix(Mat* perspMat, float fov, float aspect, float near, float far);
void makeIdentityMatrix(Mat* iMat);
void makeScalingMatrix(Mat* scaleMat, float x, float y, float z);
void makeTranslationMatrix(Mat* tranMat, float x, float y, float z);
void matrixMultiplcation(Mat* output, Mat* A, Mat* B);

#endif
