#define _USE_MATH_DEFINES

#define LEFT_KEY 1<<0
#define RIGHT_KEY 1<<1
#define UP_KEY 1<<2
#define DOWN_KEY 1<<3

#include <iostream>
#include <math.h>
#include <d3d9.h>
#include "Bryla_3D_bez_punktow.h"

using namespace System;
using namespace Microsoft::DirectX;
using namespace Microsoft::DirectX::Direct3D;
using namespace System::Windows::Forms;


#pragma once
public ref class Player_Ship
 : public Bryla_3D_bez_punktow{
public:
	Vector3 position;
	FLOAT ship_scale;
	array<FLOAT>^ points_x;
	array<FLOAT>^ points_y;
	array<FLOAT>^ points_z;
	array<Vector3>^ v1;
	array<CustomVertex::PositionNormalColored>^ ship;
	INT color;
	//Keys move_up = Keys::W;
	//Keys move_down = Keys::S;
	//Keys move_left = Keys::A;
	//Keys move_right = Keys::D;
	Keys move_up = Keys::Up;
	Keys move_down = Keys::Down;
	Keys move_left = Keys::Left;
	Keys move_right = Keys::Right;
	int length_of_ship;
	int color_for_bottom;
	int color_for_window;
	int color_for_down_part;
	int color_for_side_parts;
	int color_for_side_front_parts;
	int color_for_up_part;
	int color_for_nose;
	int multiple_keys_identifier;
	UInt16 left_key_pressed;
	UInt16 right_key_pressed;
	UInt16 up_key_pressed;
	UInt16 down_key_pressed;
	static float ship_movement_interval = 0.025f;
	int ship_pointing_direction = 1;
public:
	Player_Ship();
	Player_Ship(const Vector3& position);
	Player_Ship(const Vector3& position, const float& scale);
	Player_Ship(const Vector3& position, const float& scale, const int& color_theme);
	~Player_Ship();
public:
	virtual array<CustomVertex::PositionNormalColored>^ create_ship();
	virtual array<CustomVertex::PositionNormalColored>^ CreateShape() override;
	virtual array<CustomVertex::PositionNormalColored>^ ChangeObjectColor(const int& kol) override;
	array<CustomVertex::PositionNormalColored>^ Get_ship();
	Vector3 GetNosePosition();
	INT Get_ship_color();
	INT Length();
	Void Move_Ship(const Vector3& vector);
	Void MoveShipWithKeys();
	void Act_on_key_down(System::Windows::Forms::PreviewKeyDownEventArgs^ e);
	void Act_on_key_pressed();
	void Act_on_key_up(System::Windows::Forms::KeyEventArgs^ e);
	virtual void AssignPointsCoordinates();
	void AssignColors(const int& theme_number);
	void CheckShipPosition();
};

