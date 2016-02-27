#include"Bryla_3D.h"

#pragma once
public ref class Sign_on_screen
: Bryla_3D{
public:
	float shape_scale;
public:
	Sign_on_screen();
	~Sign_on_screen();

	array<CustomVertex::PositionNormalColored>^ CreateHorizontalBeam(const Vector3& position);
	array<CustomVertex::PositionNormalColored>^ CreateHalfOfHorizontalBeam(const Vector3& position);
	array<CustomVertex::PositionNormalColored>^ CreateVerticalBeam(const Vector3& position);
	array<CustomVertex::PositionNormalColored>^ CreateHalfOfVerticalBeam(const Vector3& position);
	array<CustomVertex::PositionNormalColored>^ CreateSmallSquare(const Vector3& position);
	void CopyBeamElements(array<CustomVertex::PositionNormalColored>^ source, array<CustomVertex::PositionNormalColored>^ object, const int& indx);
};

