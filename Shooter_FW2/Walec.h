#include "Bryla_3D.h"

#pragma once
public ref class Walec
	: Bryla_3D{
public:
	float rot_x;
	float cyl_hei;
public:
	Walec();
	Walec(const float& r, const float& height);
	Walec(const float& r, const float& height, const int& cylinder_color);
	Walec(const float& r, const float& height, const int& cylinder_color, const Vector3& cylinder_position);
	Walec(const float& r, const float& height, const int& cylinder_color, const Vector3& cylinder_position, const float& rotation_angle_around_x);
	~Walec();

public:
	virtual array<CustomVertex::PositionNormalColored>^ CreateShape() override;
	void Rotate_Cylinder_X(const float& angle);
public:
	void Funkcja_konstruktora();
};

