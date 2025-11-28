#include "vector2.h"

// Defines the box collider

#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#ifndef BOXCOLLIDER_H_DEFINED
#define BOXCOLLIDER_H_DEFINED

namespace Riconoid
{
	class BoxCollider;
}

#include "circlecollider.h"

#endif

namespace Riconoid
{
	class BoxCollider
	{
	public:
		Vector2 position;
		Vector2 size;
		Vector2 topLeft;
		Vector2 bottomRight;

		BoxCollider() {}

		BoxCollider(Vector2 position, Vector2 size)
		{
			this->size = size;

			Update(position);
		}

		bool IsValid();
		void Update(Vector2 position);
		Vector2 GetClosestPoint(Vector2 point);
		bool IsOverlapping(CircleCollider circle);
	};
}

#endif