#include "Keyboard_control.h"

using namespace System::Windows::Forms;

Keyboard_control::Keyboard_control(){
	rot_x = 0.0f;
	rot_y = 0.0f;
	rot_z = 0.0f;

	client_height = 728;
	client_width = 1024;

	view_position = Vector3(0, 0, -5);
	view_focus = Vector3(0, 0, 0);
	view_up_direction = Vector3(0, 1, 0);
	multiple_keys_identifier = 0;
	update_screen = 0;
}

Keyboard_control::Keyboard_control(const int& hei, const int& wid, Device^ dev, Vector3 position, Vector3 focus, Vector3 up_direction){
	//obliczenie wektora kierunku patrzenia
	Vector3 direction = Vector3(position.X - focus.X,position.Y-focus.Y,position.Z-focus.Z);

	rot_x = 0;
	rot_y = 0;
	rot_z = 0;
	rot_obj_x = 0;
	rot_obj_z = 0;
	original_view_position = position;
	original_view_focus = focus;
	original_view_up_direction = up_direction;

	if (position.X != 0 && position.Y != 0)
		sphere_coord_angle_fi = atanf(position.Z / sqrt(pow(position.X, 2) + pow(position.Y, 2)));
	else{
		if (position.Z > 0)
			sphere_coord_angle_fi = (float)M_PI_2;
		else if (position.Z < 0)
			sphere_coord_angle_fi = -(float)M_PI_2;
		else
			sphere_coord_angle_fi = 0;
	}
	sphere_coord_angle_theta = atan2f(position.Y, position.X);

	client_height = hei;
	client_width = wid;
	view_position = position;
	view_focus = focus;
	//dev->Transform->View
	view_up_direction = up_direction;
	multiple_keys_identifier = 0;
	device = dev;
	update_screen = 0;
}

Keyboard_control::~Keyboard_control()
{
}

void Keyboard_control::Rotate_around_X(){
	if (rot_x >M_PI)
		rot_x -= 2 * (float)M_PI;
	else if ( rot_x < -M_PI)
		rot_x += 2 * (float)M_PI;

	float R = sqrt(pow(view_position.X, 2) + pow(view_position.Y, 2) + pow(view_position.Z, 2));
	float r = sqrt(pow(R, 2) - pow(view_position.X, 2));

	view_position.Y = r * sin(rot_x);
	view_position.Z = r * -cos(rot_x);
	
	if (abs(view_position.Y)>r - 0.0001)
		view_up_direction.Y = -view_up_direction.Y;

	Update_rot_x();
	Update_rot_y();
	Update_rot_z();
}

void Keyboard_control::Rotate_around_Y(){
	if (rot_y >M_PI)
		rot_y -= 2 * (float)M_PI;
	else if (rot_y < -M_PI)
		rot_y += 2 * (float)M_PI;

	float R = sqrt(pow(view_position.X, 2) + pow(view_position.Y, 2) + pow(view_position.Z, 2));
	float r = sqrt(pow(R, 2) - pow(view_position.Y, 2));

	view_position.X = r * sin(rot_y);
	view_position.Z = r * -cos(rot_y);

	Update_rot_x();
	Update_rot_z();
}

void Keyboard_control::Rotate_around_Z(){
	if (rot_z >M_PI)
		rot_z -= 2 * (float)M_PI;
	else if (rot_z < -M_PI)
		rot_z += 2 * (float)M_PI;

	float R = sqrt(pow(view_position.X, 2) + pow(view_position.Y, 2) + pow(view_position.Z, 2));
	float r = sqrt(pow(R, 2) - pow(view_position.Z, 2));

	view_position.X = r * sin(rot_z);
	view_position.Y = r * cos(rot_z);

	Update_rot_x();
	Update_rot_y();
}

void Keyboard_control::Rotate_object_X(){
	float R = sqrt(pow(view_position.X, 2) + pow(view_position.Y, 2) + pow(view_position.Z, 2));
	float r_xz = sqrt(pow(R, 2) - pow(view_position.Y, 2));
	//trzeba policzyæ k¹t miêdzy osi¹ x, a promieniem r_xz (lub osi¹ z a tym promieniem)
	Update_rot_object_x();
	//policzyæ k¹t miedzy R a r_xz i zwiêkszyæ go, obliczaj¹c dla nowej wartoœci odpowiednie Y - trzeba respektowaæ obecny znak Y'eka
	float angle_R_to_rxz;
	if (r_xz != 0)
		if (rot_obj_x>0)
			angle_R_to_rxz = atan2f(view_position.Y, -r_xz);
		else
			angle_R_to_rxz = atan2f(view_position.Y, r_xz);
	else{
		if (view_position.Y > 0)
			angle_R_to_rxz = (float)M_PI_2;
		else
			angle_R_to_rxz = -(float)M_PI_2;
	}
	angle_R_to_rxz += 0.05f;

	view_position.Y = R*sinf(angle_R_to_rxz);

	//Dla nowego Y policzyæ nowe r_xz
	r_xz = sqrt(pow(R, 2) - pow(view_position.Y, 2));
	//Obliczyæ nowe X i Z dla znanego wczeœniej k¹ta pomiêdzy osi¹ x a promieniem r_xz
	if (abs(view_position.Y) > R-0.005*R){
		rot_obj_x += (float)M_PI;
		view_up_direction.Y = -view_up_direction.Y;
	}

	view_position.X = r_xz*cosf(rot_obj_x);
	view_position.Z = r_xz*sinf(rot_obj_x);

	Update_rot_x();
	Update_rot_y();
	Update_rot_z();
}

void Keyboard_control::Rotate_object_Y(){
	float R = sqrt(pow(view_position.X, 2) + pow(view_position.Y, 2) + pow(view_position.Z, 2));
	float r_xz = sqrt(pow(R, 2) - pow(view_position.Y, 2));
	//trzeba policzyæ k¹t miêdzy osi¹ x, a promieniem r_xz (lub osi¹ z a tym promieniem)
	Update_rot_object_x();
	//policzyæ k¹t miedzy R a r_xz i zwiêkszyæ go, obliczaj¹c dla nowej wartoœci odpowiednie Y - trzeba respektowaæ obecny znak Y'eka
	float angle_R_to_rxz;
	if (r_xz != 0)
		if (rot_obj_x>0)
			angle_R_to_rxz = atan2f(view_position.Y, -r_xz);
		else
			angle_R_to_rxz = atan2f(view_position.Y, r_xz);
	else{
		if (view_position.Y > 0)
			angle_R_to_rxz = (float)M_PI_2;
		else
			angle_R_to_rxz = -(float)M_PI_2;
	}
	rot_obj_x += 0.05f;
	view_position.Y= R*sinf(angle_R_to_rxz);
	view_position.X = r_xz*cosf(rot_obj_x);
	view_position.Z = r_xz*sinf(rot_obj_x);

	Update_rot_x();
	Update_rot_y();
	Update_rot_z();
}

void Keyboard_control::Rotate_object_Z(){
	rot_obj_z += ROTATION_STEPS;
	//nale¿y zrotowaæ wektor okreœlaj¹cy kierunek "góry" ekranu
	if (rot_obj_z >= (float)(2 * M_PI))
		rot_obj_z -= (float)(2 * M_PI);

	view_up_direction.Y = cosf(rot_obj_z);
	view_up_direction.X = sinf(rot_obj_z);
	Update_rot_x();

}

void Keyboard_control::Calc_camera_up_direction(){
}

void Keyboard_control::ZoomIn(){
	Get_spherical_angle_fi();
	Get_spherical_angle_theta();
	float R = sqrt(pow(view_position.X, 2) + pow(view_position.Y, 2) + pow(view_position.Z, 2));

	R -= 0.05f;

	view_position.X = R*cosf(sphere_coord_angle_theta)*cosf(sphere_coord_angle_fi);
	view_position.Y = R*cos(sphere_coord_angle_fi)*sin(sphere_coord_angle_theta);
	view_position.Z = R*sin(sphere_coord_angle_fi);

	Update_rot_x();
	Update_rot_y();
	Update_rot_z();

}

void Keyboard_control::ZoomOut(){
	Get_spherical_angle_fi();
	Get_spherical_angle_theta();
	float R = sqrt(pow(view_position.X, 2) + pow(view_position.Y, 2) + pow(view_position.Z, 2));

	R += 0.05f;

	view_position.X = R*cosf(sphere_coord_angle_theta)*cosf(sphere_coord_angle_fi);
	view_position.Y = R*cos(sphere_coord_angle_fi)*sin(sphere_coord_angle_theta);
	view_position.Z = R*sin(sphere_coord_angle_fi);

	Update_rot_x();
	Update_rot_y();
	Update_rot_z();
}

void Keyboard_control::Rotate_around_X(float angle){
	//Aby obróciæ widok nale¿y znaæ aktualn¹ pozycjê kamery i zacz¹æ wykonywaæ ruch po okrêgu z zablokowanym wymiarem wokó³ którego
	//ma zostaæ wykonany obrót
}

void Keyboard_control::Rotate_around_Y(float angle){

}

void Keyboard_control::Rotate_around_Z(float angle){

}

void Keyboard_control::Change_camera_position(){

}

void Keyboard_control::Change_camera_focus(){

}

void Keyboard_control::Change_up_direction(){

}

void Keyboard_control::Change_camera_position(Vector3 new_position){
	view_position = new_position;
}

void Keyboard_control::Change_camera_focus(Vector3 new_position){
	view_focus = new_position;
}

void Keyboard_control::Change_up_direction(Vector3 new_direction){
	view_up_direction = new_direction;
}

void Keyboard_control::Act_on_key_down(System::Windows::Forms::PreviewKeyDownEventArgs^ e){
	if (e->KeyCode == space_bar){
		shot_enable = true;
	}
	else if (e->KeyCode == move_left){
		multiple_keys_identifier |= LEFT_KEY;
	}	
	else if (e->KeyCode == move_right){
		multiple_keys_identifier |= RIGHT_KEY;
	}
	else if (e->KeyCode == move_up){
		multiple_keys_identifier |= UP_KEY;
	}
	else if (e->KeyCode == move_down){
		multiple_keys_identifier |= DOWN_KEY;
	}
	else if (e->KeyCode == centre_view){
		multiple_keys_identifier |= CENTRE_VIEW_KEY;
	}
	else if (e->KeyCode == rotate_around_x_plus){
		multiple_keys_identifier |= ROT_X_PLUS_KEY;
	}
	else if (e->KeyCode == rotate_around_x_minus){
		multiple_keys_identifier |= ROT_X_MINUS_KEY;
	}
	else if (e->KeyCode == rotate_around_y_plus){
		multiple_keys_identifier |= ROT_Y_PLUS_KEY;
	}
	else if (e->KeyCode == rotate_around_y_minus){
		multiple_keys_identifier |= ROT_Y_MINUS_KEY;
	}
	else if (e->KeyCode == rotate_around_z_plus){
		multiple_keys_identifier |= ROT_Z_PLUS_KEY;
	}
	else if (e->KeyCode == rotate_around_z_minus){
		multiple_keys_identifier |= ROT_Z_MINUS_KEY;
	}
	else if (e->KeyCode == zoom){
		multiple_keys_identifier |= ZOOM_KEY;
	}
	else if (e->KeyCode == unzoom){
		multiple_keys_identifier |= UNZOOM_KEY;
	}
	else if (e->KeyCode == rotate_obj_x){
		multiple_keys_identifier |= ROT_OBJECT_X;
	}
	else if (e->KeyCode == rotate_obj_y){
		multiple_keys_identifier |= ROT_OBJECT_Y;
	}
	else if (e->KeyCode == rotate_obj_z){
		multiple_keys_identifier |= ROT_OBJECT_Z;
	}
}

void Keyboard_control::Act_on_key_pressed(System::Windows::Forms::KeyPressEventArgs^ e){
	//if(multiple_keys_identifier & LEFT_KEY){
	//	view_position += Vector3(-single_view_incrementation, 0, 0);
	//	view_focus += Vector3(-single_view_incrementation, 0, 0);
	//	//this->Change_camera_position();
	//}
	//if (multiple_keys_identifier & RIGHT_KEY){
	//	view_position += Vector3(single_view_incrementation, 0, 0);
	//	view_focus += Vector3(single_view_incrementation, 0, 0);
	//	//this->Change_camera_position();
	//}
	//if (multiple_keys_identifier & UP_KEY){
	//	view_position += Vector3(0, -single_view_incrementation, 0);
	//	view_focus += Vector3(0, -single_view_incrementation, 0);
	//	//this->Change_camera_position();
	//}
	//if (multiple_keys_identifier & DOWN_KEY){
	//	view_position += Vector3(0, single_view_incrementation, 0);
	//	view_focus += Vector3(0, single_view_incrementation, 0);
	//	//this->Change_camera_position();
	//}
	if (multiple_keys_identifier & CENTRE_VIEW_KEY){
		view_position = original_view_position;
		view_focus = original_view_focus;
		view_up_direction = original_view_up_direction;
		Update_rot_x();
		Update_rot_y();
		Update_rot_z();
		Update_rot_object_z();
	}
	if (multiple_keys_identifier & ROT_X_PLUS_KEY){
		rot_x += ROTATION_STEPS;
		this->Rotate_around_X();
	}
	if (multiple_keys_identifier & ROT_X_MINUS_KEY){
		rot_x -= ROTATION_STEPS;
		this->Rotate_around_X();
	}
	if (multiple_keys_identifier & ROT_Y_PLUS_KEY){
		rot_y += ROTATION_STEPS;
		this->Rotate_around_Y();
	}
	if (multiple_keys_identifier & ROT_Y_MINUS_KEY){
		rot_y -= ROTATION_STEPS;
		this->Rotate_around_Y();
	}
	if (multiple_keys_identifier & ROT_Z_PLUS_KEY){
		rot_z += ROTATION_STEPS;
		this->Rotate_around_Z();
	}
	if (multiple_keys_identifier & ROT_Z_MINUS_KEY){
		rot_z -= ROTATION_STEPS;
		this->Rotate_around_Z();
	}
	if (multiple_keys_identifier & ZOOM_KEY){
		this->ZoomIn();
	}
	if (multiple_keys_identifier & UNZOOM_KEY){
		this->ZoomOut();
	}
	if (multiple_keys_identifier & ROT_OBJECT_X){
		this->Rotate_object_X();
	}
	if (multiple_keys_identifier & ROT_OBJECT_Y){
		this->Rotate_object_Y();
	}
	if (multiple_keys_identifier & ROT_OBJECT_Z){
		this->Rotate_object_Z();
	}
}

void Keyboard_control::Act_on_key_up(System::Windows::Forms::KeyEventArgs^ e){
	if (e->KeyCode == space_bar){
		shot_enable = false;
		constant_shooting = false;
	}
	if (e->KeyCode == move_left){
		multiple_keys_identifier &= ~LEFT_KEY;
	}
	else if (e->KeyCode == move_right){
		multiple_keys_identifier &= ~RIGHT_KEY;
	}
	else if (e->KeyCode == move_up){
		multiple_keys_identifier &= ~UP_KEY;
	}
	else if (e->KeyCode == move_down){
		multiple_keys_identifier &= ~DOWN_KEY;
	}
	else if (e->KeyCode == centre_view){
		multiple_keys_identifier &= ~CENTRE_VIEW_KEY;
	}
	else if (e->KeyCode == rotate_around_x_plus){
		multiple_keys_identifier &= ~ROT_X_PLUS_KEY;
	}
	else if (e->KeyCode == rotate_around_x_minus){
		multiple_keys_identifier &= ~ROT_X_MINUS_KEY;
	}
	else if (e->KeyCode == rotate_around_y_plus){
		multiple_keys_identifier &= ~ROT_Y_PLUS_KEY;
	}
	else if (e->KeyCode == rotate_around_y_minus){
		multiple_keys_identifier &= ~ROT_Y_MINUS_KEY;
	}
	else if (e->KeyCode == rotate_around_z_plus){
		multiple_keys_identifier &= ~ROT_Z_PLUS_KEY;
	}
	else if (e->KeyCode == rotate_around_z_minus){
		multiple_keys_identifier &= ~ROT_Z_MINUS_KEY;
	}
	else if (e->KeyCode == zoom){
		multiple_keys_identifier &= ~ZOOM_KEY;
	}
	else if (e->KeyCode == unzoom){
		multiple_keys_identifier &= ~UNZOOM_KEY;
	}
	else if (e->KeyCode == rotate_obj_x){
		multiple_keys_identifier &= ~ROT_OBJECT_X;
	}
	else if (e->KeyCode == rotate_obj_y){
		multiple_keys_identifier &= ~ROT_OBJECT_Y;
	}
	else if (e->KeyCode == rotate_obj_z){
		multiple_keys_identifier &= ~ROT_OBJECT_Z;
	}
}


Vector3 Keyboard_control::Get_view_position(){
	return view_position;
}

Vector3 Keyboard_control::Get_view_focus(){
	return view_focus;
}

Vector3 Keyboard_control::Get_view_up_direction(){
	return view_up_direction;
}

void Keyboard_control::Get_spherical_angle_fi(){
	if (view_position.X != 0 && view_position.Y != 0)
		sphere_coord_angle_fi = atanf(view_position.Z / sqrt(pow(view_position.X, 2) + pow(view_position.Y, 2)));
	else{
		if (view_position.Z > 0)
			sphere_coord_angle_fi = (float)M_PI_2;
		else if (view_position.Z < 0)
			sphere_coord_angle_fi = -(float)M_PI_2;
		else
			sphere_coord_angle_fi = 0;
	}
}

void Keyboard_control::Get_spherical_angle_theta(){
	if (view_position.X != 0 && view_position.Y != 0)
		sphere_coord_angle_theta = atan2f(view_position.Y, view_position.X);
	else{
		if (view_position.Z > 0)
			sphere_coord_angle_theta = (float)M_PI;
		else if (view_position.Z < 0)
			sphere_coord_angle_theta = 0;
		else
			sphere_coord_angle_theta = 0;
	}
}

void Keyboard_control::Update_rot_x(){
	if (view_position.Z != 0 && view_position.Y != 0)
		rot_x = atan2f(view_position.Y, -view_position.Z);
	else
		rot_x = 0;

	update_screen = 1;
}

void Keyboard_control::Update_rot_y(){
	if (view_position.X != 0 && view_position.Z != 0)
		rot_y = atan2f(view_position.X, -view_position.Z);
	else
		rot_y = 0;
}

void Keyboard_control::Update_rot_z(){
	if (view_position.X != 0 && view_position.Y != 0)
		rot_z = atan2f(view_position.X, view_position.Y);
	else
		rot_z = 0;
}

void Keyboard_control::Update_rot_object_x(){
	if (view_position.Z != 0 || view_position.X != 0)
		rot_obj_x = atan2f(view_position.Z, view_position.X);
	else{
		if (view_position.Z > 0)
			rot_obj_x += (float)M_PI_2;
		else
			rot_obj_x -= (float)M_PI_2;
	}
}

void Keyboard_control::Update_rot_object_z(){
	if (view_position.Z != 0 && view_position.X != 0)
		rot_obj_z = atan2f(view_up_direction.Y, view_up_direction.X);
	else{
		rot_obj_z += (float)M_PI;
	}
}

int Keyboard_control::GetUpdateStatus(){
	if (update_screen == 1)
		return 1;
	else
		return 0;
}

void Keyboard_control::ScreenUpdated(){
	update_screen = 0;
}

bool Keyboard_control::GetShotConstant(){
	return constant_shooting;
}

void Keyboard_control::SetShotConstant(bool log){
	constant_shooting = log;
}

void Keyboard_control::ShotOnceDone(){
	shot_enable = false;
	time_of_last_shot = global_time;
}

bool Keyboard_control::Shot(){
	return shot_enable;
}

void Keyboard_control::ShotDone(){
	constant_shooting = false;
	time_of_last_shot = global_time;
}

float Keyboard_control::GetTimeOfLastShot(){
	return time_of_last_shot;
}

void Keyboard_control::SetTimeOfLastShot(float time){
	time_of_last_shot = time;
}

void Keyboard_control::Update_global_time(float time){
	global_time = time;
}

float Keyboard_control::GetGlobalTime(){
	return global_time;
}

bool Keyboard_control::CheckForConstantShot(){
	if (shot_enable == true){
		constant_shooting = true;
	}
	return constant_shooting;
}