#include "planecollider.h"

using namespace Riconoid;

// This file represents plane collider functionality

bool PlaneCollider::IsValid()
{
	// Return if the plane's normal is non-zero

	return !normal.IsZero();
}