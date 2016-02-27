#include "Walec.h"


Walec::Walec(){
	shape_scale = 1.0f;
	shape_color = Drawing::Color::Brown.ToArgb();
	shape_position = Vector3(0, 0, 0);
	cyl_hei = 1.0f;
	rot_x = 0.0f;
	Funkcja_konstruktora();
}

Walec::Walec(const float& r, const float& height){
	shape_scale = r;
	cyl_hei = height;
	shape_color = Drawing::Color::Brown.ToArgb();
	shape_position = Vector3(0, 1, 2);
	rot_x = 0.0f; 
	Funkcja_konstruktora();
}

Walec::Walec(const float& r, const float& height, const int& cylinder_color){
	shape_scale = r;
	cyl_hei = height;
	shape_color = cylinder_color;
	shape_position = Vector3(0, 0, 0);
	rot_x = 0.0f;
	Funkcja_konstruktora();
}

Walec::Walec(const float& r, const float& height, const int& cylinder_color, const Vector3& cylinder_position){
	shape_scale = r;
	cyl_hei = height;
	shape_color = cylinder_color;
	shape_position = cylinder_position;
	rot_x = 0.0f;
	Funkcja_konstruktora();
}

Walec::Walec(const float& r, const float& height, const int& cylinder_color, const Vector3& cylinder_position, const float& rotation_angle_around_x){
	shape_scale = r;
	cyl_hei = height;
	shape_color = cylinder_color;
	shape_position = cylinder_position;
	rot_x = rotation_angle_around_x;
	Funkcja_konstruktora();
}

Walec::~Walec()
{
}

array<CustomVertex::PositionNormalColored>^ Walec::CreateShape(){
	array<CustomVertex::PositionNormalColored>^ cylinder = gcnew array<CustomVertex::PositionNormalColored>(731);
	int counter = 0;
	float add = -shape_scale*1.0f;
	float cyl_height = cyl_hei;


	array<Vector3>^ v1 = gcnew array<Vector3>(731);
	points_x[0] = shape_position.X;
	points_y[0] = shape_position.Y - 0.5f*cyl_height*sinf(rot_x + (float)M_PI_2);
	points_z[0] = shape_position.Z - 0.5f*cyl_height*cosf(rot_x + (float)M_PI_2);
	counter = 1;
	v1[0] = Vector3(points_x[0], points_y[0], points_z[0]);
	
	for (double angle = 0; angle <= 2 * M_PI + M_PI_2 / 45; angle += M_PI_2 / 45){ //czyli co 2 stopnie kolejny bok tr�jk�ta
		points_x[counter] = shape_position.X + add*cosf((float)angle);
		points_y[counter] = shape_position.Y - 0.5f*cyl_height*sinf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*sinf(rot_x);
		points_z[counter] = shape_position.Z - 0.5f*cyl_height*cosf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*cosf(rot_x);
		v1[counter++] = Vector3(points_x[counter], points_y[counter], points_z[counter]);
	}
	int cyl_count = 0;
	for (int i = 0; i < counter; i++){
		cylinder[i++] = CustomVertex::PositionNormalColored(v1[0], v1[0], shape_color);
		cylinder[i] = CustomVertex::PositionNormalColored(v1[i], v1[i], shape_color);
		cyl_count = i;
	}
	//zako�czone sk�adanie dolnej podstawy


	for (double angle = 0; angle <= 2 * M_PI + M_PI_2 / 45; angle += M_PI_2 / 45){ //czyli co 2 stopnie kolejny bok tr�jk�ta
		points_x[counter] = shape_position.X + add*cosf((float)angle);
		points_y[counter] = shape_position.Y + 0.5f*cyl_height*sinf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*sinf(rot_x);
		points_z[counter] = shape_position.Z + 0.5f*cyl_height*cosf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*cosf(rot_x);
		v1[counter++] = Vector3(points_x[counter], points_y[counter], points_z[counter]);
		points_x[counter] = shape_position.X + add*cosf((float)angle);
		points_y[counter] = shape_position.Y - 0.5f*cyl_height*sinf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*sinf(rot_x);
		points_z[counter] = shape_position.Z - 0.5f*cyl_height*cosf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*cosf(rot_x);
		v1[counter++] = Vector3(points_x[counter], points_y[counter], points_z[counter]);
	}
	int ii = cyl_count;
	while(ii <counter){
		cylinder[ii++] = CustomVertex::PositionNormalColored(v1[ii], v1[ii], shape_color);
		cylinder[ii++] = CustomVertex::PositionNormalColored(v1[ii], v1[ii], shape_color);
	}
	//zako�czono sk�adanie powierzchnii walcowej
	
	////przej�cie do g�rnej podstawy
	//cylinder[ii] = CustomVertex::PositionNormalColored(v1[ii-1], v1[ii-1], shape_color);
	//cylinder[ii+1] = CustomVertex::PositionNormalColored(v1[ii - 1], v1[ii - 1], shape_color);

	cyl_count = counter;
	ii = 0;
	while (ii<183){
		v1[counter++] = Vector3(points_x[ii], points_y[ii] + cyl_height*sinf(rot_x + (float)(M_PI_2)), points_z[ii] + cyl_height*cosf(rot_x + (float)(M_PI_2)));
		ii++;
	}
	Vector3 v2 = Vector3(points_x[0], points_y[0] + sinf(rot_x + (float)(M_PI_2))*cyl_height, points_z[0] + cosf(rot_x + (float)(M_PI_2))*cyl_height);
	for (int i = cyl_count; i < counter; i++){
		cylinder[i++] = CustomVertex::PositionNormalColored(v2, v2, shape_color);
		cylinder[i] = CustomVertex::PositionNormalColored(v1[i], v1[i], shape_color);
	}
	//zako�czone sk�adanie dolnej podstawy

	return cylinder;
}


void Walec::Funkcja_konstruktora(){
	points_x = gcnew array < FLOAT >(547);
	points_y = gcnew array < FLOAT >(547);
	points_z = gcnew array < FLOAT >(547);
	shape_ptr = CreateShape();
}

void Walec::Rotate_Cylinder_X(const float& angle){

}