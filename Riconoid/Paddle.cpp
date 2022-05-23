#include "paddle.h"

using namespace Riconoid;

// This file represents the paddle that is controlled by the player

void Paddle::Update()
{
	GameObject::Update();

	// Update the paddle's x coordinate based on the mouse position
	// whilst still being clamped within the wall boundaries
	position.x = fmax(minMove + boxCollider.size.x, fmin(GetMousePosition().x, maxMove - boxCollider.size.x));
}

void Paddle::Draw()
{
	// Draw the paddle

	DrawRectangle(position.x - boxCollider.size.x, position.y - boxCollider.size.y, boxCollider.size.x * 2, boxCollider.size.y * 2, { colliderColour.r, colliderColour.g, colliderColour.b, 100 });
	DrawRectangleLines(position.x - boxCollider.size.x, position.y - boxCollider.size.y, boxCollider.size.x * 2, boxCollider.size.y * 2, colliderColour);
}