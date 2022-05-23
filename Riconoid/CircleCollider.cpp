#include "circlecollider.h"

// This file represents circle collider functionality

using namespace Riconoid;

bool CircleCollider::IsValid()
{
	// Returns if the circle's radius is non-zero

	return radius != 0;
}

void CircleCollider::Update(Vector2 position)
{
	// Update the collider's position

	this->position = position;
}

Vector2 CircleCollider::GetClosestPoint(Vector2 point)
{
	// Returns a point inside the circle closest to the specified vector point

	Vector2 distance = point - position;

	if (distance.Magnitude() > radius * radius)
		distance = distance.Normalize() * radius;

	return position + distance;
}

bool CircleCollider::IsOverlapping(BoxCollider box)
{
	// Checks if the circle collider is overlapping with a box collider

	Vector2 difference = box.GetClosestPoint(position) - position;

	return difference.Dot(difference) <= (radius * radius);
}