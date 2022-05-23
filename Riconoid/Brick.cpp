#include "brick.h"

using namespace Riconoid;

// This file pretty much just draws the brick game object

void Brick::Draw()
{
	// Draw the brick

	DrawRectangle(position.x - boxCollider.size.x, position.y - boxCollider.size.y, boxCollider.size.x * 2, boxCollider.size.y * 2, { colliderColour.r, colliderColour.g, colliderColour.b, 100 });
	DrawRectangleLines(position.x - boxCollider.size.x, position.y - boxCollider.size.y, boxCollider.size.x * 2, boxCollider.size.y * 2, colliderColour);
}