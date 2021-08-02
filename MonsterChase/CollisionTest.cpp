#include "CollisionTest.h"
#include <xlocinfo>
#include <windows.h>

void _CollisionTest::test(_SmartPointer::SmartPointer<_GameObject::GameObject> actor1, _SmartPointer::SmartPointer<_GameObject::GameObject> actor2)
{
	const size_t	lenBuffer = 65;
	char			Buffer[lenBuffer];
	_Collision::AABBCollision(actor1, actor2);
	sprintf_s(Buffer, lenBuffer, "collision test: is separated %s\n", _Collision::AABBCollision(actor1, actor2) ? "true" : "false");
	OutputDebugStringA(Buffer);
}
