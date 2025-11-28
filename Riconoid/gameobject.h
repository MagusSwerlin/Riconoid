#include <vector>
#include <string>
#include <raylib.h>
#include "vector2.h"
#include "boxcollider.h"
#include "circlecollider.h"
#include "planecollider.h"
#include "ray.h"

// Defines the base game object

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

namespace Riconoid
{
	class GameObject
	{
	public:
		bool pendingDeletion = false;

		Vector2 position;

		BoxCollider boxCollider;
		CircleCollider circleCollider;
		PlaneCollider planeCollider;

		Color colliderColour = WHITE;

		GameObject() {}

		GameObject(Vector2 location)
		{
			this->position = location;
		}

		GameObject(Vector2 location, Vector2 boxColliderSize)
		{
			this->position = location;
			this->boxCollider = BoxCollider(location, boxColliderSize);
		}

		GameObject(Vector2 location, float circleColliderRadius)
		{
			this->position = location;
			this->circleCollider = CircleCollider(location, circleColliderRadius);
		}

		GameObject(Vector2 location, Vector2 planeCollider_p1, Vector2 planeCollider_p2)
		{
			this->position = location;
			this->planeCollider = PlaneCollider(planeCollider_p1, planeCollider_p2);
		}

		void LoadSprite(std::string filename);
		virtual void Update();
		virtual void Draw();
		virtual void Destroy();
	};
}

#endif