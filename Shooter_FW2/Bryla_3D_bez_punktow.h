#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <d3d9.h>
#include "Intersections.h"

using namespace System;
using namespace Microsoft::DirectX;
using namespace Microsoft::DirectX::Direct3D;

public ref class Bryla_3D_bez_punktow
	: Intersections{
public:
	array<CustomVertex::PositionNormalColored>^ shape_ptr;
	Vector3 shape_position;
public:
	Bryla_3D_bez_punktow();
	~Bryla_3D_bez_punktow();

	array<CustomVertex::PositionNormalColored>^ GetShape();
	INT GetShapePtrLength();

	virtual array<CustomVertex::PositionNormalColored>^ CreateShape();
	virtual array<CustomVertex::PositionNormalColored>^ ChangeObjectColor(const int& kol);
	Vector3 GetPosition();
	Void MoveShape(const Vector3& vector);
	Void MoveShapeTo(const Vector3& vector);
};

