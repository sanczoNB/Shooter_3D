#pragma once

using namespace Microsoft::DirectX;

public ref class Detect_Intersections
{
public:
	Detect_Intersections();
	~Detect_Intersections();

	bool CalculateForShoting(array<Vector3>^ shot_coord, array<Vector3>^ obj_coord);
	bool CalculatePlayerShipForShoting(array<Vector3>^ shot_coord, array<Vector3>^ obj_coord);
	bool CalculateForHitingPlayerShip(array<Vector3>^ pl_ship_coord, array<Vector3>^ obj_coord);
};

