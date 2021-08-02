#include "Vector4Test.h"
#include <xlocinfo>
#include <windows.h>
using namespace _Vector4;
void _Vector4Test::test()
{
	const size_t	lenBuffer = 65;
	char			Buffer[lenBuffer];

	Vector4D test(1, 1, 1, 1);
	Vector4D test2(2, 2, 2, 2);

	sprintf_s(Buffer, lenBuffer, "vector test 1 %s\n", test == test2 ? "true" : "false"); 
	OutputDebugStringA(Buffer);

	sprintf_s(Buffer, lenBuffer, "vector test 2 %s\n", test != test2 ? "true" : "false"); 
	OutputDebugStringA(Buffer);

	Vector4D test3(3, 3, 3, 3);

	sprintf_s(Buffer, lenBuffer, "vector test 3 %s\n", (test + test2) == test3 ? "true" : "false");
	OutputDebugStringA(Buffer);
}
