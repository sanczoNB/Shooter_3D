#pragma once
#include "Bryla_3D_bez_punktow.h"

public ref class Shot
 : Bryla_3D_bez_punktow{
private:
	static int points_assigned = 0;
	float rot_x = (float)(M_PI_2);
	float shape_scale = 0.02f;
	float cyl_height = 0.25f;
	int shape_color;
public:
	static Vector3 v2;
	static int znacznik_konca;
	static int drugi_znacznik;
	static array<FLOAT>^ points_x = gcnew array < FLOAT >(547);
	static array<FLOAT>^ points_y = gcnew array < FLOAT >(547);
	static array<FLOAT>^ points_z = gcnew array < FLOAT >(547);
	static array<Vector3>^ v1 = gcnew array<Vector3>(731);
public:
	Shot();
	Shot(const Vector3 position);
	Shot(const Vector3 position, const int& color);
	~Shot();
public:
	virtual array<CustomVertex::PositionNormalColored>^ CreateShape() override;
	void Assign_Coordinates();

};

