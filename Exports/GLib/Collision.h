#pragma once
#include "GameObject.h"
#include "SmartPointer.h"
#include <list>
namespace _Collision {
	bool AABBCollision(_SmartPointer::SmartPointer<_GameObject::GameObject> actor1, _SmartPointer::SmartPointer<_GameObject::GameObject> actor2);
	void CheckCollision(std::list<_SmartPointer::SmartPointer<_GameObject::GameObject>> actors);
	void CollisionResponse(_SmartPointer::SmartPointer<_GameObject::GameObject> actor, int CollisionType);
}
