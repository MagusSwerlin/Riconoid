#include "vector2.h"

// Defines the plane collider

#ifndef PLANECOLLIDER_H
#define PLANECOLLIDER_H

#ifndef PLANECOLLIDER_H_DEFINED
#define PLANECOLLIDER_H_DEFINED

namespace Riconoid
{
	class PlaneCollider;
}

#include "circlecollider.h"

#endif

namespace Riconoid
{
	class PlaneCollider
	{
	public:
		Vector2 pointA;
		Vector2 pointB;
		Vector2 normal;
		float scale = 0;

		enum PlaneResult : int
		{
			Front = 1,
			Back = -1,
			Intersect = 0
		};

		PlaneCollider() {}

		PlaneCollider(Vector2 a, Vector2 b)
		{
			Vector2 vector = b - a;
			vector.Normalize();

			this->pointA = a;
			this->pointB = b;
			this->normal.x = -vector.y;
			this->normal.y = vector.x;
			this->scale = -a.Dot(normal);
		}

		bool IsValid();
	};
}

#endif