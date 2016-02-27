#define _USE_MATH_DEFINES
#include <iostream>
#include "Bryla_3D.h"
#include <math.h>
#include <d3d9.h>

using namespace System;
using namespace Microsoft::DirectX;
using namespace Microsoft::DirectX::Direct3D;

#pragma once
public ref class Kula
	: Bryla_3D
{
private:
	FLOAT r;
	Vector3 position;
	//array<CustomVertex::PositionNormalColored>^ kula;
	INT kolor_kuli;

public:
	Kula();
	Kula(Kula^ k);
	Kula(FLOAT R, Vector3 pos, INT color);
	~Kula();

	//array<CustomVertex::PositionNormalColored>^ utworz_kule(double& r, array<Double>^& pts_x, array<Double>^& pts_y, array<Double>^& pts_z);
public:
	array<CustomVertex::PositionNormalColored>^ utworz_kule();
	array<CustomVertex::PositionNormalColored>^ Get_kula();
	virtual array<CustomVertex::PositionNormalColored>^ CreateShape() override;
	FLOAT Kula::Get_r();
	Vector3 Get_position();
	INT Get_kolor_kuli();
	INT Length();
	Void Move_Kula(const Vector3& vector);
};

