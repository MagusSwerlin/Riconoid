#include "vector2.h"

using namespace Riconoid;

// This file represents 2d vector functionality

bool Vector2::IsZero()
{
	// Returns if this vector is zero

	return x == 0 && y == 0;
}

float Vector2::Magnitude()
{
	// Get the magnitude of the vector

	return (float)sqrt(x * x + y * y);
}

float Vector2::MagnitudeSqr()
{
	// Get the squared magnitude of the vector

	float magnitude = MagnitudeSqr();

	return magnitude * magnitude;
}

float Vector2::Dot(Vector2 vector)
{
	// Return a dot product from this and another vector

	return x * vector.x + y * vector.y;
}

Vector2 Vector2::Normalize()
{
	// Normalizes the vector

	float magnitude = Magnitude();

	if (magnitude <= 0)
		return { x, y };

	x = x / magnitude;
	y = y / magnitude;

	return { x, y };
}

Vector2 Vector2::Clamp(Vector2 min, Vector2 max)
{
	// Clamps this vector between two other vectors

	Vector2 vector = Max(min, Min(max, { x, y }));

	x = vector.x;
	y = vector.y;

	return { x, y };
}

Vector2 Vector2::Min(Vector2 a, Vector2 b)
{
	// Returns the minimum vector between two

	return { fmin(a.x, b.x), fmin(a.y, b.y) };
}

Vector2 Vector2::Max(Vector2 a, Vector2 b)
{
	// Returns the maximum vector between two

	return { fmax(a.x, b.x), fmax(a.y, b.y) };
}

// Useful operator overloads for vectors

Vector2 operator -(Vector2 vector)
{
	return vector * -1;
}

Vector2 Vector2::operator +(Vector2 vector)
{
	return { x + vector.x, y + vector.y };
}

Vector2 Vector2::operator +=(Vector2 vector)
{
	x = x + vector.x;
	y = y + vector.y;

	return { x , y };
}

Vector2 Vector2::operator -(Vector2 vector)
{
	return { x - vector.x, y - vector.y };
}

Vector2 Vector2::operator *(Vector2 vector)
{
	return { x * vector.x, y * vector.y };
}

Vector2 Vector2::operator *=(Vector2 vector)
{
	x = x * vector.x;
	y = y * vector.y;

	return { x , y };
}

Vector2 Vector2::operator /(Vector2 vector)
{
	return { x / vector.x, y / vector.y };
}

Vector2 Vector2::operator *(float scale)
{
	return { x * scale, y * scale };
}

Vector2 Vector2::operator /(float division)
{
	return { x / division, y / division };
}