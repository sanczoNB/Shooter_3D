#pragma once
#include "Bryla_3D.h"

public ref class Szescian
	: Bryla_3D
{
public:
	Szescian();
	Szescian(const float& cubic_scale);
	Szescian(const float& cubic_scale, const int& cube_color);
	Szescian(const float& cubic_scale, const int& cube_color, const Vector3& cube_position);
	~Szescian();


	virtual array<CustomVertex::PositionNormalColored>^ CreateShape() override;
//	virtual Vector3 GetPosition() override;
//	virtual Void MoveShape(const Vector3& vector) override;
};

