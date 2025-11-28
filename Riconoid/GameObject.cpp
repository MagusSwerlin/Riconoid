#include "gameobject.h"

// This file represents the functionality of all game objects

using namespace Riconoid;

void GameObject::Update()
{
	// Update either box and or circle colliders if they are valid

	if (boxCollider.IsValid())
		boxCollider.Update(position);

	if (circleCollider.IsValid())
		circleCollider.Update(position);
}

void GameObject::Draw()
{
	// Draw any of the valid colliders

	if (boxCollider.IsValid())
		DrawRectangleLines(position.x, position.y, boxCollider.size.x, boxCollider.size.y, colliderColour);

	if (circleCollider.IsValid())
		DrawCircleLines(circleCollider.position.x, circleCollider.position.y, circleCollider.radius, colliderColour);

	if (planeCollider.IsValid())
		DrawLine(planeCollider.pointA.x, planeCollider.pointA.y, planeCollider.pointB.x, planeCollider.pointB.y, colliderColour);
}

void GameObject::Destroy()
{
	// Set the game object to be deleted on the next game update iteration

	pendingDeletion = true;
}