#pragma once
#include "Bryla_3D_bez_punktow.h"

public ref class Bryla_3D
	: Bryla_3D_bez_punktow{
public:
	INT shape_color;
	FLOAT shape_scale;
	array<FLOAT>^ points_x;
	array<FLOAT>^ points_y;
	array<FLOAT>^ points_z;


public:
	Bryla_3D();
	~Bryla_3D();
	
	
	INT GetShapeColor();
	//virtual array<CustomVertex::PositionNormalColored>^ CreateShape() override;
	
};

