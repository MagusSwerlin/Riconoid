#include "vector2.h"

// Defines the circle collider

#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

#ifndef CIRCLECOLLIDER_H_DEFINED
#define CIRCLECOLLIDER_H_DEFINED

namespace Riconoid
{
	class CircleCollider;
}

#include "boxcollider.h"

#endif

namespace Riconoid
{
	class CircleCollider
	{
	public:
		Vector2 position;
		int radius = 0;

		CircleCollider() {}

		CircleCollider(Vector2 position, float radius)
		{
			this->position = position;
			this->radius = radius;
		}

		bool IsValid();
		void Update(Vector2 position);
		Vector2 GetClosestPoint(Vector2 point);
		bool IsOverlapping(BoxCollider box);
	};
}

#endif