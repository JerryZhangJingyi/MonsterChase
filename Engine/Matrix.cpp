#include "Matrix.h"
#include "FloatHelper.h"
#include <corecrt_math.h>
using namespace _Matrix;
using namespace _FloatHelper;
_Matrix::Matrix::Matrix(float r1c1_, float r2c1_, float r3c1_, float r4c1_, float r1c2_, float r2c2_, float r3c2_, float r4c2_, float r1c3_, float r2c3_, float r3c3_, float r4c3_, float r1c4_, float r2c4_, float r3c4_, float r4c4_) :
	r1c1(r1c1_),
	r1c2(r1c2_),
	r1c3(r1c3_),
	r1c4(r1c4_),

	r2c1(r2c1_),
	r2c2(r2c2_),
	r2c3(r2c3_),
	r2c4(r2c4_),

	r3c1(r3c1_),
	r3c2(r3c2_),
	r3c3(r3c3_),
	r3c4(r3c4_),

	r4c1(r4c1_),
	r4c2(r4c2_),
	r4c3(r4c3_),
	r4c4(r4c4_)
{
}

_Matrix::Matrix::Matrix(const Matrix& matrix) : 
	r1c1(matrix.r1c1),
	r1c2(matrix.r1c2),
	r1c3(matrix.r1c3),
	r1c4(matrix.r1c4),

	r2c1(matrix.r2c1),
	r2c2(matrix.r2c2),
	r2c3(matrix.r2c3),
	r2c4(matrix.r2c4),

	r3c1(matrix.r3c1),
	r3c2(matrix.r3c2),
	r3c3(matrix.r3c3),
	r3c4(matrix.r3c4),

	r4c1(matrix.r4c1),
	r4c2(matrix.r4c2),
	r4c3(matrix.r4c3),
	r4c4(matrix.r4c4)
{
}

Matrix _Matrix::Matrix::operator*(Matrix& matrix)
{
	Matrix temp;
	return Matrix
	(temp.r1c1 = r1c1 * matrix.r1c1 + r1c2 * matrix.r2c1 + r1c3 * matrix.r3c1 + r1c4 * matrix.r4c1,
		temp.r1c2 = r1c1 * matrix.r1c2 + r1c2 * matrix.r2c2 + r1c3 * matrix.r3c2 + r1c4 * matrix.r4c2,
		temp.r1c3 = r1c1 * matrix.r1c3 + r1c2 * matrix.r2c3 + r1c3 * matrix.r3c3 + r1c4 * matrix.r4c3,
		temp.r1c4 = r1c1 * matrix.r1c4 + r1c2 * matrix.r2c4 + r1c3 * matrix.r3c4 + r1c4 * matrix.r4c4,
		
		temp.r2c1 = r2c1 * matrix.r1c1 + r2c2 * matrix.r2c1 + r2c3 * matrix.r3c1 + r2c4 * matrix.r4c1,
		temp.r2c2 = r2c1 * matrix.r1c2 + r2c2 * matrix.r2c2 + r2c3 * matrix.r3c2 + r2c4 * matrix.r4c2,
		temp.r2c3 = r2c1 * matrix.r1c3 + r2c2 * matrix.r2c3 + r2c3 * matrix.r3c3 + r2c4 * matrix.r4c3,
		temp.r2c4 = r2c1 * matrix.r1c4 + r2c2 * matrix.r2c4 + r2c3 * matrix.r3c4 + r2c4 * matrix.r4c4,
		
		temp.r3c1 = r3c1 * matrix.r1c1 + r3c2 * matrix.r2c1 + r3c3 * matrix.r3c1 + r3c4 * matrix.r4c1,
		temp.r3c2 = r3c1 * matrix.r1c2 + r3c2 * matrix.r2c2 + r3c3 * matrix.r3c2 + r3c4 * matrix.r4c2,
		temp.r3c3 = r3c1 * matrix.r1c3 + r3c2 * matrix.r2c3 + r3c3 * matrix.r3c3 + r3c4 * matrix.r4c3,
		temp.r3c4 = r3c1 * matrix.r1c4 + r3c2 * matrix.r2c4 + r3c3 * matrix.r3c4 + r3c4 * matrix.r4c4,
		
		temp.r4c1 = r4c1 * matrix.r1c1 + r4c2 * matrix.r2c1 + r4c3 * matrix.r3c1 + r4c4 * matrix.r4c1,
		temp.r4c2 = r4c1 * matrix.r1c2 + r4c2 * matrix.r2c2 + r4c3 * matrix.r3c2 + r4c4 * matrix.r4c2,
		temp.r4c3 = r4c1 * matrix.r1c3 + r4c2 * matrix.r2c3 + r4c3 * matrix.r3c3 + r4c4 * matrix.r4c3,
		temp.r4c4 = r4c1 * matrix.r1c4 + r4c2 * matrix.r2c4 + r4c3 * matrix.r3c4 + r4c4 * matrix.r4c4 );
}

bool _Matrix::Matrix::operator==(Matrix& matrix)
{
	return (AboutEqual(r1c1, matrix.r1c1) && AboutEqual(r1c2, matrix.r1c2) && AboutEqual(r1c3, matrix.r1c3) && AboutEqual(r1c4, matrix.r1c4)
	&& AboutEqual(r2c1, matrix.r2c1) && AboutEqual(r2c2, matrix.r2c2) && AboutEqual(r2c3, matrix.r2c3) && AboutEqual(r2c4, matrix.r2c4)
	&& AboutEqual(r3c1, matrix.r3c1) && AboutEqual(r3c2, matrix.r3c2) && AboutEqual(r3c3, matrix.r3c3) && AboutEqual(r3c4, matrix.r3c4)
	&& AboutEqual(r4c1, matrix.r4c1) && AboutEqual(r4c2, matrix.r4c2) && AboutEqual(r4c3, matrix.r4c3) && AboutEqual(r4c4, matrix.r4c4));
}

void _Matrix::Matrix::Transpose(Matrix matrix)
{
	float temp = matrix.r2c1;
	matrix.r2c1 = matrix.r1c2;
	matrix.r1c2 = temp;

	temp = matrix.r3c1;
	matrix.r3c1 = matrix.r1c3;
	matrix.r1c3 = temp;

	temp = matrix.r4c1;
	matrix.r4c1 = matrix.r1c4;
	matrix.r1c4 = temp;

	temp = matrix.r3c2;
	matrix.r3c2 = matrix.r2c3;
	matrix.r2c3 = temp;

	temp = matrix.r4c2;
	matrix.r4c2 = matrix.r2c4;
	matrix.r2c4 = temp;

	temp = matrix.r4c3;
	matrix.r4c3 = matrix.r3c4;
	matrix.r3c4 = temp;
}

void _Matrix::Matrix::Inversion(Matrix matrix)
{
	float s0 = matrix.r1c1 * matrix.r2c2 - matrix.r2c1 * matrix.r1c2;
	float s1 = matrix.r1c1 * matrix.r2c3 - matrix.r2c3 * matrix.r1c3;
	float s2 = matrix.r1c1 * matrix.r2c4 - matrix.r2c1 * matrix.r1c4;
	float s3 = matrix.r1c2 * matrix.r2c3 - matrix.r2c2 * matrix.r1c3;
	float s4 = matrix.r1c2 * matrix.r2c4 - matrix.r2c2 * matrix.r1c4;
	float s5 = matrix.r1c3 * matrix.r2c4 - matrix.r1c3 * matrix.r1c4;

	float c5 = matrix.r3c3 * matrix.r4c4 - matrix.r4c3 * matrix.r3c4;
	float c4 = matrix.r3c2 * matrix.r4c4 - matrix.r4c2 * matrix.r3c4;
	float c3 = matrix.r3c2 * matrix.r4c3 - matrix.r4c2 * matrix.r3c3;
	float c2 = matrix.r3c1 * matrix.r4c4- matrix.r4c1 * matrix.r3c4;
	float c1 = matrix.r3c1 * matrix.r4c3 - matrix.r4c1 * matrix.r4c3;
	float c0 = matrix.r3c1 * matrix.r4c2 - matrix.r4c1 * matrix.r3c2;

	float invdet = 1.0 / (s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0);

	Matrix temp = matrix;

	matrix.r1c1 = (temp.r2c2 * c5 - temp.r2c3 * c4 + temp.r2c4 * c3) * invdet;
	matrix.r1c2 = (-temp.r1c2 * c5 + temp.r1c3 * c4 - temp.r1c4 * c3) * invdet;
	matrix.r1c3 = (temp.r4c2 * s5 - temp.r4c3 * s4 + temp.r4c4 * s3) * invdet;
	matrix.r1c4 = (-temp.r3c2 * s5 + temp.r3c3 * s4 - temp.r3c4* s3) * invdet;

	matrix.r2c1 = (-temp.r2c1 * c5 + temp.r2c3* c2 - temp.r2c4 * c1) * invdet;
	matrix.r2c2 = (temp.r1c1 * c5 - temp.r1c3 * c2 + temp.r1c4 * c1) * invdet;
	matrix.r2c3 = (-temp.r4c1 * s5 + temp.r4c3 * s2 - temp.r4c4 * s1) * invdet;
	matrix.r2c4 = (temp.r3c1 * s5 - temp.r3c3 * s2 + temp.r3c4 * s1) * invdet;

	matrix.r3c1 = (temp.r2c1 * c4 - temp.r2c2 * c2 + temp.r2c4 * c0) * invdet;
	matrix.r3c2 = (-temp.r1c1 * c4 + temp.r1c2* c2 - temp.r1c4 * c0) * invdet;
	matrix.r3c3 = (temp.r4c1 * s4 - temp.r4c2 * s2 + temp.r4c4 * s0) * invdet;
	matrix.r3c4 = (-temp.r3c1 * s4 + temp.r3c2 * s2 - temp.r3c4 * s0) * invdet;

	matrix.r4c1 = (-temp.r2c1 * c3 + temp.r2c2 * c1 - temp.r2c3 * c0) * invdet;
	matrix.r4c2 = (temp.r1c1 * c3 - temp.r1c2 * c1 + temp.r1c3 * c0) * invdet;
	matrix.r4c3 = (-temp.r4c1 * s3 + temp.r4c2 * s1 - temp.r4c3 * s0) * invdet;
	matrix.r4c4 = (temp.r3c1 * s3 - temp.r3c2 * s1 + temp.r3c3 * s0) * invdet;
}

void _Matrix::Matrix::Transform(Matrix matrix, float x, float y, float z)
{
	Matrix transform
	(1.0, 0.0f, 0.0f, x,
		0.0f, 1.0f, 0.0f, y,
		0.0f, 0.0f, 1.0f, z,
		0.0f, 0.0f, 0.0f, 1.0f);

	matrix = matrix * transform;
}

void _Matrix::Matrix::XRotation(Matrix matrix, float angle)
{
	Matrix xRotation
	(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cosf(angle), -sinf(angle), 0.0f,
		0.0f, sinf(angle), cosf(angle), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);

	matrix = matrix * xRotation;
}

void _Matrix::Matrix::YRotation(Matrix matrix, float angle)
{
	Matrix yRotation
	(cosf(angle), 0, sinf(angle), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		-sinf(angle), 0.0f, cosf(angle), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);

	matrix = matrix * yRotation;
}

void _Matrix::Matrix::ZRotation(Matrix matrix, float angle)
{
	Matrix zRotation
	(cosf(angle), -sinf(angle), 0.0f, 0.0f,
		sinf(angle), cosf(angle), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);

	matrix = matrix * zRotation;
}

void _Matrix::Matrix::Scale(Matrix matrix, float value)
{
	Matrix scale
	(value, 0.0f, 0.0f, 0.0f,
		0.0f, value, 0.0f, 0.0f,
		0.0f, 0.0f, value, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);

	matrix = matrix * scale;
}

Vector4D _Matrix::Matrix::MultiplyVector4(Matrix matrix, Vector4D vector)
{
	Vector4D result;
	result.x = matrix.r1c1 * vector.x + matrix.r1c2 * vector.x + matrix.r1c3 * vector.x + matrix.r1c4 * vector.x;
	result.y = matrix.r2c1 * vector.y + matrix.r2c2 * vector.y + matrix.r2c3 * vector.y + matrix.r2c4 * vector.y;
	result.z = matrix.r3c1 * vector.z + matrix.r3c2 * vector.z + matrix.r3c3 * vector.z + matrix.r3c4 * vector.z;
	result.w = matrix.r4c1 * vector.w + matrix.r4c2 * vector.w + matrix.r4c3 * vector.w + matrix.r4c4 * vector.w;

	return result;
}

