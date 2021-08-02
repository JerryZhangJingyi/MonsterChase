#include "Bullet.h"

_SmartPointer::SmartPointer<_GameObject::GameObject> _Bullet::UpdateBullet(_SmartPointer::SmartPointer<_GameObject::GameObject> bullet, int direction)
{
	if (direction == 0)
	{
		bullet->Y += bullet->velocity;
	}
	else if (direction == 1)
	{
		bullet->X += bullet->velocity;
	}
	else if (direction == 2)
	{
		bullet->Y -= bullet->velocity;
	}
	else if (direction == 3)
	{
		bullet->X -= bullet->velocity;
	}

	return bullet;
}
