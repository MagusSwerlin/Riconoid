#include "boxcollider.h"

// This file represents box collider functionality

using namespace Riconoid;

bool BoxCollider::IsValid()
{
	// Returns if the size of the box is non-zero

	return !size.IsZero();
}

void BoxCollider::Update(Vector2 position)
{
	// Update the collider's position

	this->position = position;

	topLeft = position - size;
	bottomRight = position + size;
}

Vector2 BoxCollider::GetClosestPoint(Vector2 point)
{
	// Returns a point inside the box closest to the specified vector point

	return point.Clamp(topLeft, bottomRight);
}

bool BoxCollider::IsOverlapping(CircleCollider circle)
{
	// Checks if the box collider is overlapping with a circle collider

	Vector2 difference = GetClosestPoint(circle.position) - circle.position;

	return difference.Dot(difference) <= (circle.radius * circle.radius);
}