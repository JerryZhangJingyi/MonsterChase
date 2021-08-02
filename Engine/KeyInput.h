#pragma once
#include "GameObject.h"
namespace _KeyInput {
	struct KeyValue
	{
		_GameObject::GameObject actor;
		bool quit;
		float force;
		bool keyPressed;
		int direction;
		bool fire;
	};
	KeyValue checkInput(_GameObject::GameObject actor, bool quit, float deltaTime);
}