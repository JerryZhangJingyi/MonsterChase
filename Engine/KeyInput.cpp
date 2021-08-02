#include "KeyInput.h"
#include "Physics.h"
#include <windows.h>
using namespace _KeyInput;

KeyValue _KeyInput::checkInput(_GameObject::GameObject actor, bool quit, float deltaTime)
{
	float force = 0;
	KeyValue value;
	value.keyPressed = false;
	value.fire = false;
	if (GetAsyncKeyState('W') & 0x8000)
	{
		actor.Y += actor.velocity;
		value.direction = 0;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		actor.X += actor.velocity;
		value.direction = 1;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		actor.Y -= actor.velocity;
		value.direction = 2;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		actor.X -= actor.velocity;
		value.direction = 3;
	}

	if (GetAsyncKeyState('Q') & 0x8000)
	{
		value.keyPressed = true;
		quit = true;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		value.fire = true;
	}

	/*
	if (value.keyPressed == false && actor.Y > -300)
	{
		actor.Y = _Physics::UpdatePhysics(actor, -0.5, deltaTime);
	}
	*/
	value.actor = actor;
	value.quit = quit;
	value.force = force;
	return value;
}
