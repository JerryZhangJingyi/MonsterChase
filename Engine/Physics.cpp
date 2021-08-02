#include "Physics.h"

float _Physics::UpdatePhysics(_GameObject::GameObject actor, float force, float deltaTime)
{
	actor.velocity = actor.velocity + force * deltaTime;
	actor.Y = actor.Y + actor.velocity * deltaTime;

	return actor.Y;
}

