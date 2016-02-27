#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

#define LEFT_KEY 1<<0
#define RIGHT_KEY 1<<1
#define UP_KEY 1<<2
#define DOWN_KEY 1<<3
#define ROT_X_PLUS_KEY 1<<4
#define ROT_X_MINUS_KEY 1<<5
#define ROT_Y_PLUS_KEY 1<<6
#define ROT_Y_MINUS_KEY 1<<7
#define ROT_Z_PLUS_KEY 1<<8
#define ROT_Z_MINUS_KEY 1<<9
#define ZOOM_KEY 1<<10
#define UNZOOM_KEY 1<<11
#define ROT_OBJECT_X 1<<12
#define ROT_OBJECT_Y 1<<13
#define ROT_OBJECT_Z 1<<14
#define CENTRE_VIEW_KEY 1<<15
#define MAX_NUM_OF_KEYS 16
#define ROTATION_STEPS ((float)M_PI/50)


using namespace std;
using namespace Microsoft::DirectX;
using namespace Microsoft::DirectX::Direct3D;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;



#pragma once
ref class Keyboard_control
{
protected:
	float global_time;
	float time_of_last_shot;
	bool constant_shooting;
	bool shot_enable;
	int client_height;
	int client_width;
	float single_view_incrementation = 0.05f;
	//char rot_x_plus = 'r';
	//char rot_x_minus = 'f';
	//char rot_y_plus = 't';
	//char rot_y_minus = 'g';
	//char rot_z_plus = 'y';
	//char rot_z_minus = 'h';
	Keys space_bar = Keys::Space;
	Keys zoom = Keys::Z;
	Keys unzoom = Keys::X;
	//Keys move_up = Keys::W;
	//Keys move_down = Keys::S;
	//Keys move_left = Keys::A;
	//Keys move_right = Keys::D;
	Keys move_up = Keys::Up;
	Keys move_down = Keys::Down;
	Keys move_left = Keys::Left;
	Keys move_right = Keys::Right;
	Keys centre_view = Keys::Q;
	Keys rotate_around_x_plus = Keys::R;
	Keys rotate_around_x_minus = Keys::F;
	Keys rotate_around_y_plus = Keys::T;
	Keys rotate_around_y_minus = Keys::G;
	Keys rotate_around_z_plus = Keys::Y;
	Keys rotate_around_z_minus = Keys::H;
	Keys rotate_obj_x = Keys::C;
	Keys rotate_obj_y = Keys::V;
	Keys rotate_obj_z = Keys::B;
	

private:
	int update_screen;
	float rot_x;
	float rot_y;
	float rot_z;
	float sphere_coord_angle_theta;
	float sphere_coord_angle_fi;
	float rot_obj_x;
	float rot_obj_z;
	
	int multiple_keys_identifier;
	Device^ device;
	Vector3 original_view_position;
	Vector3 original_view_focus;
	Vector3 original_view_up_direction;
	Vector3 view_position;
	Vector3 view_focus;
	Vector3 view_up_direction;


public:
	Keyboard_control();
	Keyboard_control(const int& hei, const int& wid, Device^ dev, Vector3 position, Vector3 focus, Vector3 up_position);
	~Keyboard_control();

public:
	void Rotate_around_X();
	void Rotate_around_Y();
	void Rotate_around_Z();
	void Rotate_around_X(float angle);
	void Rotate_around_Y(float angle);
	void Rotate_around_Z(float angle);
	void Rotate_object_X();
	void Rotate_object_Y();
	void Rotate_object_Z();

	void Change_camera_position();
	void Change_camera_focus();
	void Change_up_direction();
	void Change_camera_position(Vector3 new_position);
	void Change_camera_focus(Vector3 new_position);
	void Change_up_direction(Vector3 new_direction);
	void Act_on_key_down(System::Windows::Forms::PreviewKeyDownEventArgs^ e);
	void Act_on_key_pressed(System::Windows::Forms::KeyPressEventArgs^ e);
	void Act_on_key_up(System::Windows::Forms::KeyEventArgs^ e);
	Vector3 Get_view_position();
	Vector3 Get_view_focus();
	Vector3 Get_view_up_direction();
	void ShotOnceDone();
	bool GetShotConstant();
	void SetShotConstant(bool log);
	bool Shot();
	void ShotDone();
	void Get_spherical_angle_fi();
	void Get_spherical_angle_theta();
	void Update_rot_x();
	void Update_rot_y();
	void Update_rot_z();
	void Update_rot_object_x();
	void Update_rot_object_z();
	void ZoomIn();
	void ZoomOut();
	void Calc_camera_up_direction();
	int GetUpdateStatus();
	void ScreenUpdated();
	float GetTimeOfLastShot();
	void SetTimeOfLastShot(float time);
	void Update_global_time(float time);
	float GetGlobalTime();
	bool CheckForConstantShot();

};

