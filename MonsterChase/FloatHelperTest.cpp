#include "FloatHelperTest.h"
#include <xlocinfo>
#include <windows.h>

void _FloatHelperTest::test()
{
	const size_t	lenBuffer = 65;
	char			Buffer[lenBuffer];

	sprintf_s(Buffer, lenBuffer, "float test 1 %s\n", _FloatHelper::IsNaN(3.0f) ? "true" : "false"); //false
	OutputDebugStringA(Buffer);

	sprintf_s(Buffer, lenBuffer, "float test 2 %s\n", _FloatHelper::IsNaN(nanf("foo")) ? "true" : "false"); //true
	OutputDebugStringA(Buffer);

	sprintf_s(Buffer, lenBuffer, "float test 3 %s\n", _FloatHelper::AboutEqual(1.f, 2.f) ? "true" : "false"); //false
	OutputDebugStringA(Buffer);

	sprintf_s(Buffer, lenBuffer, "float test 4 %s\n", _FloatHelper::AboutEqual(1.f, 1.00001f) ? "true" : "false"); //true
	OutputDebugStringA(Buffer);

	sprintf_s(Buffer, lenBuffer, "float test 5 %s\n", _FloatHelper::IsZero(0.0001f) ? "true" : "false"); //false
	OutputDebugStringA(Buffer);

	sprintf_s(Buffer, lenBuffer, "float test 6 %s\n", _FloatHelper::IsZero(0.000000000000001f) ? "true" : "false"); //true
	OutputDebugStringA(Buffer);
}
