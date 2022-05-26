#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "planecollider.h"
#include "gameplay.h"

// This file represents the ball game object

using namespace Riconoid;

void Ball::Update()
{
	// Called via update from the inherited base "GameObject" class
	GameObject::Update();

	// Used to prevents the ball from destroying multiple bricks in once bounce
	canHitBrick = true;

	// Process the ball's movement
	position += velocity * speed;
	ray.origin = position;
	ray.direction = velocity;

	// The for loop iterates through the static "gameobjects" vector to check for collisions
	for (GameObject* gameObject : Gameplay::gameObjects)
	{
		// If the game object has a plane collider, then it is a wall
		if (gameObject->planeCollider.IsValid())
		{
			// The returned reflection vector from the ball's raycast
			Riconoid::Vector2 reflection = ray.GetReflection(gameObject->planeCollider).Normalize();

			// "IsZero" just means that the reflection is a zero vector, so this is used to check if the reflection actually occured or not
			if (!reflection.IsZero())
			{
				// If there is a bounce, then speed the ball up
				SpeedUp();

				// If the plane collider is vertical, that means it's a side wall, so do an adjustment to the reflection vector
				if (gameObject->planeCollider.pointA.x == gameObject->planeCollider.pointB.x)
				{
					// This makes it so the ball adjusts itself a little after bouncing on one of the side walls
					// The reason for this is to prevent the ball from bouncing tediously if the reflection angle is very small

					Riconoid::Vector2 center = { (float)(Gameplay::screenWidth / 2), velocity.y < 0 ? 0.0f : (float)Gameplay::screenHeight };
					velocity = (reflection + (center - position).Normalize()).Normalize();
				}
				else // Otherwise, just set the velocity to the reflection since adjustment is not needed
					velocity = reflection;
			}
		}

		// If the gameobject has a box collider, then it is either the player's paddle, or a brick
		if (gameObject->boxCollider.IsValid())
		{
			Riconoid::Vector2 reflection = ray.GetReflection(gameObject->boxCollider).Normalize();

			if (!reflection.IsZero())
			{
				velocity = reflection;

				SpeedUp();

				// "dynamic_cast" is used to check if the game object is of specified type
				// So in this case, check if it was the player's Paddle game object
				if (dynamic_cast<Paddle*>(gameObject) != nullptr)
				{
					// Use a mouse delta function to allow the player to "flick" the ball a little
					// in the desired horizontal direction, so that the ball's bounce isn't always mundane

					RAYLIB_H::Vector2 mouseDelta = GetMouseDelta();
					Riconoid::Vector2 delta = { mouseDelta.x, mouseDelta.x > 0 ? -mouseDelta.x : mouseDelta.x };

					velocity = (reflection + delta).Normalize();

					// And after bouncing off the paddle, check if there's no bricks left
					// If so, build some more out again

					if (Gameplay::bricksLeft == 0)
						Gameplay::BuildBricks();
				}
				else // Otherwise, check if the game object was a brick
					if (dynamic_cast<Brick*>(gameObject) != nullptr && canHitBrick)
					{
						canHitBrick = false;

						gameObject->Destroy();

						Gameplay::score++;
						Gameplay::bricksLeft--;
					}
			}
		}
	}

	// Checks if the ball is below a certain y-axis level
	// If so, then it is out of bounds and the player loses a life
	if (position.y > Gameplay::screenHeight + circleCollider.radius * 20)
	{
		// If the player's lives are above zero, decrement it and reset the ball
		if (Gameplay::lives > 0)
		{
			Gameplay::lives--;

			Reset(origin);
		}
		else // Otherwise, game over
			Gameplay::gameIsOver = true;
	}
}

void Ball::Draw()
{
	// Draw the ball

	DrawCircle(position.x, position.y, circleCollider.radius, { colliderColour.r, colliderColour.g, colliderColour.b, 100 });
	DrawCircleLines(position.x, position.y, circleCollider.radius, colliderColour);
}

void Ball::SpeedUp()
{
	// Speeds the ball up and increases its raycast's length by the ball's acceleration factor

	speed += speed < maxSpeed ? accFactor : 0;
	ray.length += speed < maxSpeed ? accFactor : 0;
}

void Ball::Reset(Riconoid::Vector2 location)
{
	// Reset the ball to its origin position and base speed

	speed = baseSpeed;
	position = location;
	origin = location;
	ray.length = circleCollider.radius;

	float angle = GetRandomValue(-2.0f, 2.0f);

	// Prevents the ball from going straight up
	while (angle == 0)
		angle = GetRandomValue(-2.0f, 2.0f);

	velocity = Riconoid::Vector2(angle, -1).Normalize();
}