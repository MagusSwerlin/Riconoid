#include "gameobject.h"

// Defines the paddle game object

#ifndef PADDLE_H
#define PADDLE_H

class Paddle : public Riconoid::GameObject
{
public:
	int minMove;
	int maxMove;

	Paddle() {}

	Paddle(Riconoid::Vector2 location, Riconoid::Vector2 colliderSize, int minMove, int maxMove)
	{
		this->position = location;
		this->minMove = minMove;
		this->maxMove = maxMove;

		boxCollider.size = colliderSize;
	}

	void Update();
	void Draw();
};

#endif