#include <cmath>

// Defines the 2d vector class

#ifndef VECTOR2_H
#define VECTOR2_H

namespace Riconoid
{
	class Vector2
	{
	public:
		float x = 0;
		float y = 0;

		Vector2() {}

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		bool IsZero();
		float Magnitude();
		float MagnitudeSqr();
		float Dot(Vector2 vector);
		Vector2 Normalize();
		Vector2 Min(Vector2 a, Vector2 b);
		Vector2 Max(Vector2 a, Vector2 b);
		Vector2 Clamp(Vector2 min, Vector2 max);
		Vector2 operator -(Vector2 vector);
		Vector2 operator +(Vector2 vector);
		Vector2 operator +=(Vector2 vector);
		Vector2 operator *(Vector2 vector);
		Vector2 operator *=(Vector2 vector);
		Vector2 operator /(Vector2 vector);
		Vector2 operator *(float scale);
		Vector2 operator /(float division);
	};
}

#endif