#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include "matrix.h"
#include <string.h>

void makeRotationMatrix(Mat* rotMat, float angle)
{
	makeIdentityMatrix(rotMat);
	float c = cos(angle);
	float s = sin(angle);

	rotMat->arr[0] = c;
	rotMat->arr[2] = s;
	rotMat->arr[8] = -s;
	rotMat->arr[10] = c;

}

void makeTransformationMatrix(Mat* tranMat, float x, float y, float z)
{
	makeIdentityMatrix(tranMat);
	tranMat->arr[12] = x;
	tranMat->arr[13] = y;
	tranMat->arr[14] = z;
}

void makePerspectiveMatrix(Mat* perspMat, float fov, float aspect, float near, float far)
{
    	float f = 1.0 / tan(fov / 2.0);
    	float nf = 1.0 / (near - far);
	
	for(int i = 0; i < 16; i++)
	{
		perspMat->arr[i] = 0.f;
	}

	perspMat->arr[0] = f / aspect;
	perspMat->arr[5] = f;
	perspMat->arr[10] = (far + near) * nf;
	perspMat->arr[11] = -1.f;
	perspMat->arr[14] = (2.f * far * near) * nf;
}

void makeIdentityMatrix(Mat* iMat)
{
	for(int i = 0; i < 16; i++)
	{
		iMat->arr[i] = 0.f;
	}

	iMat->arr[0] = 1.f;
	iMat->arr[5] = 1.f;
	iMat->arr[10] = 1.f;
	iMat->arr[15] = 1.f;

}

void makeScalingMatrix(Mat* scaleMat, float x, float y, float z)
{
	makeIdentityMatrix(scaleMat);
	scaleMat->arr[0] = x;
	scaleMat->arr[5] = y;
	scaleMat->arr[10] = z;
}

void makeTranslationMatrix(Mat* tranMat, float x, float y, float z)
{
	makeIdentityMatrix(tranMat);
	tranMat->arr[12] = x;
	tranMat->arr[13] = y;
	tranMat->arr[14] = z;
}

void matrixMultiplcation(Mat* output, Mat* A, Mat* B)
{
	Mat result;

	for(int col = 0; col < 4; col++)
	{
		for(int row = 0; row < 4; row++)
		{	
			result.arr[col * 4 + row] =
				A->arr[row] * B->arr[col * 4] +
				A->arr[4 + row] * B->arr[col * 4  + 1] +
				A->arr[2 * 4 + row] * B->arr[col * 4  + 2] +
				A->arr[3 * 4 + row] * B->arr[col * 4 + 3];
		}
	}

	*output = result;
}

