#include "gameobject.h"

// Defines the ball game object

#ifndef BALL_H
#define BALL_H

class Ball : public Riconoid::GameObject
{
public:
	float speed;
	float baseSpeed;
	float maxSpeed;
	float accFactor;
	bool canHitBrick = true;
	Riconoid::Vector2 origin;
	Riconoid::Vector2 velocity;
	Riconoid::Ray ray;

	Ball(float size, float speed, float maxSpeed, float accFactor)
	{
		this->speed = speed;
		this->baseSpeed = speed;
		this->maxSpeed = maxSpeed;
		this->accFactor = accFactor;

		ray.length = size;
		circleCollider.radius = size;
	}

	void Reset(Riconoid::Vector2 location);
	void SpeedUp();
	void Update();
	void Draw();
};

#endif