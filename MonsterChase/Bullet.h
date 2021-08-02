#pragma once
#include "GameObject.h"
#include "SmartPointer.h"
namespace _Bullet {
	_SmartPointer::SmartPointer<_GameObject::GameObject> UpdateBullet(_SmartPointer::SmartPointer<_GameObject::GameObject> bullet, int direction);
}