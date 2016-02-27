#pragma once

using namespace Microsoft::DirectX;

public ref class Intersections{
public:
	array<Vector3>^ intersect_pts;
private:
	array<Vector3>^ intersection_points;
public:
	Intersections();
	~Intersections();

	void SetIntersectionPoints(array<Vector3>^ pointer);
	array<Vector3>^ GetIntersectionPoints();
};

