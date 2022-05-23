#include "vector2.h"

// Defines the raycast class

#ifndef RAY_H
#define RAY_H

#ifndef RAY_H_DEFINED
#define RAY_H_DEFINED

namespace Riconoid
{
	class Ray;
}

#include "planecollider.h"
#include "boxcollider.h"

#endif

namespace Riconoid
{
	class Ray
	{
	public:
		Vector2 origin;
		Vector2 direction;
		float length = 0;

		Ray() {}

		Ray(Vector2 origin, Vector2 direction, float length)
		{
			this->origin = origin;
			this->direction = direction;
			this->length = length;
		}

		Vector2 GetReflection(PlaneCollider plane);
		Vector2 GetReflection(BoxCollider plane);
	};
}

#endif
