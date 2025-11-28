#include "ray.h"

using namespace Riconoid;

// This file represents raycasting functionality

Vector2 Ray::GetReflection(PlaneCollider plane)
{
	// Get a reflected vector off of a plane collider
	// Returns a zero-vector if there's no reflection

	float d = direction.Dot(plane.normal);

	if (d > 0)
		return { 0, 0 };

	float t = origin.Dot(plane.normal) + plane.scale;

	if (d == 0 && t != 0)
		return { 0, 0 };

	d = t == 0 ? 0 : -(t / d);

	if (d >= 0 &&
		d <= length)
	{
		Vector2 P = direction * (length - d);
		float p = P.Dot(plane.normal);

		return plane.normal * -2 * p + P;
	}

	return { 0, 0 };
}

Vector2 Ray::GetReflection(BoxCollider box)
{
	// Get a reflected vector off of a box collider
	// Returns a zero-vector if there's no reflection

	float xmin, xmax, ymin, ymax;

	if (direction.x < 0)
	{
		xmin = (box.bottomRight.x - origin.x) / direction.x;
		xmax = (box.topLeft.x - origin.x) / direction.x;
	}
	else
	{
		xmin = (box.topLeft.x - origin.x) / direction.x;
		xmax = (box.bottomRight.x - origin.x) / direction.x;
	}

	if (direction.y < 0)
	{
		ymin = (box.bottomRight.y - origin.y) / direction.y;
		ymax = (box.topLeft.y - origin.y) / direction.y;
	}
	else
	{
		ymin = (box.topLeft.y - origin.y) / direction.y;
		ymax = (box.bottomRight.y - origin.y) / direction.y;
	}

	if (xmin > ymax || ymin > xmax)
		return { 0, 0 };

	float t = fmax(xmin, ymin);

	if (t >= 0 && t <= length)
	{
		Vector2 N;

		if (t == xmin)
		{
			if (direction.x < 0)
				N = { 1, 0 };
			else
				N = { -1, 0 };
		}
		else
		{
			if (direction.y < 0)
				N = { 0, 1 };
			else
				N = { 0, -1 };
		}

		Vector2 P = direction * (length - t);
		float p = P.Dot(N);

		return N * -2 * p + P; ;
	}

	return { 0, 0 };
}