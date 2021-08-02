#include "MatrixTest.h"
#include "Vector4.h"
#include <xlocinfo>
#include <windows.h>

using namespace _Matrix;
using namespace _Vector4;
void _MatrixTest::test()
{
	const size_t	lenBuffer = 200;
	char			Buffer[lenBuffer];

	Matrix test
	(1, 2, 1, 2, 
		1, 2, 1, 2,
		3, 4, 3, 4,
		3, 4, 3, 4);

	Matrix checkTransponse
	(1, 1, 3, 3,
		2, 2, 4, 4,
		1, 1, 3, 3,
		2, 2, 4, 4);

	Matrix::Transpose(test);

	sprintf_s(Buffer, lenBuffer, "matrix test 1 \n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n", test.r1c1, test.r1c2, test.r1c3, test.r1c4,
		test.r2c1, test.r2c2, test.r2c3, test.r2c4,
		test.r3c1, test.r3c2, test.r3c3, test.r3c4,
		test.r4c1, test.r4c2, test.r4c3, test.r4c4);
	OutputDebugStringA(Buffer);

	Matrix test2
	(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	Matrix checkInverse
	(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	Matrix::Inversion(test2);

	sprintf_s(Buffer, lenBuffer, "matrix test 2 \n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n", test2.r1c1, test2.r1c2, test2.r1c3, test2.r1c4,
		test2.r2c1, test2.r2c2, test2.r2c3, test2.r2c4,
		test2.r3c1, test2.r3c2, test2.r3c3, test2.r3c4,
		test2.r4c1, test2.r4c2, test2.r4c3, test2.r4c4);
	OutputDebugStringA(Buffer);

	Matrix test3
	(1, 2, 1, 2,
	1, 2, 1, 2,
	1, 2, 1, 2,
	1, 2, 1, 2);

	Matrix test4
	(3, 4, 3, 4,
	3, 4, 3, 4,
	3, 4, 3, 4,
	3, 4, 3, 4);

	Matrix checkMult
	(18, 24, 18, 24,
		18, 24, 18, 24,
		18, 24, 18, 24,
		18, 24, 18, 24);

	Matrix mutlResult = test3 * test4;

	sprintf_s(Buffer, lenBuffer, "matrix test 3 \n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n", 
		mutlResult.r1c1, mutlResult.r1c2, mutlResult.r1c3, mutlResult.r1c4,
		mutlResult.r2c1, mutlResult.r2c2, mutlResult.r2c3, mutlResult.r2c4,
		mutlResult.r3c1, mutlResult.r3c2, mutlResult.r3c3, mutlResult.r3c4,
		mutlResult.r4c1, mutlResult.r4c2, mutlResult.r4c3, mutlResult.r4c4);
	OutputDebugStringA(Buffer);

	Vector4D test5
	(1, 2, 3, 4);

	Vector4D checkMultiVector
	(36, 36, 36, 36);

	Vector4D vectorResult = Matrix::MultiplyVector4(test4, test5);

	sprintf_s(Buffer, lenBuffer, "matrix test 4 \n%f %f %f %f\n",
		vectorResult.x, vectorResult.y, vectorResult.z, vectorResult.w);
	OutputDebugStringA(Buffer);
	//sprintf_s(Buffer, lenBuffer, "matrix test 4 %s\n", checkMultiVector == Matrix::MultiplyVector4(test4, test5) ? "pass" : "fail");

}
