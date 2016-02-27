#pragma once
#include "Bryla_3D.h"

public ref class Czworoscian
	: Bryla_3D
{
public:
	Czworoscian();
	Czworoscian(const float& tethraedron_scale);
	Czworoscian(const float& tethraedron_scale, const int& tethraedron_color);
	Czworoscian(const float& tethraedron_scale, const int& tethraedron_color, const Vector3& tethraedron_position);
	~Czworoscian();

	virtual array<CustomVertex::PositionNormalColored>^ CreateShape() override;
};

