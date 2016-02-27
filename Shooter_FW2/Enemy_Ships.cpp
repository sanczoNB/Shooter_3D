#include "Enemy_Ships.h"


Enemy_Ships::Enemy_Ships(const Vector3& pos)
{
	points_x = gcnew array<FLOAT>(17);
	points_y = gcnew array<FLOAT>(17);
	points_z = gcnew array<FLOAT>(17);
	v1 = gcnew array<Vector3>(17);
	position = pos;
	//ship_movement_interval -= 0.05f;
	CheckShipPosition();
	position.Z = pos.Z;
	shape_position = position;
	color = System::Drawing::Color::Red.ToArgb();
	ship_scale = 0.55f;
	AssignColors(0);
	intersect_pts = gcnew array<Vector3>(2);
	ship_pointing_direction = -1;
	ship = create_ship();
	
	//ReverseShip();
}


Enemy_Ships::~Enemy_Ships()
{
}

void Enemy_Ships::RandomShipMove(const int& direction){
	switch (direction){
	case 0: { up_key_pressed = 0; down_key_pressed = 0; right_key_pressed = 0; left_key_pressed = 0; } break;
	//ruch w prawo i w górê
	case 1: {up_key_pressed = 1; down_key_pressed = 0; } break;
	case 2:	{right_key_pressed = 1; left_key_pressed = 0; } break;
	case 3: {down_key_pressed = 1; up_key_pressed = 0; } break;
	case 4: {left_key_pressed = 1; right_key_pressed = 0; } break;
	case 5: {up_key_pressed = 1; right_key_pressed = 1; down_key_pressed = 0; left_key_pressed = 0; } break;
	case 6: {down_key_pressed = 1; right_key_pressed = 1; up_key_pressed = 0; left_key_pressed = 0; } break;
	case 7: {up_key_pressed = 1; left_key_pressed = 1; down_key_pressed = 0; right_key_pressed = 0; } break;
	case 8: {down_key_pressed = 1; left_key_pressed = 1; up_key_pressed = 0; right_key_pressed = 0; } break;
	//default: {up_key_pressed = 0; down_key_pressed = 0; right_key_pressed = 0; left_key_pressed = 0; } break;
	}
	this->Act_on_key_pressed();
}