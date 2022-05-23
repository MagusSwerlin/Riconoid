#include "gameobject.h"

// Defines the brick game object

#ifndef BRICK_H
#define BRICK_H

class Brick : public Riconoid::GameObject
{
public:
	Brick(Riconoid::Vector2 location, Riconoid::Vector2 colliderSize)
	{
		this->position = location;

		boxCollider.size = colliderSize;
	}

	void Draw();
};

#endif