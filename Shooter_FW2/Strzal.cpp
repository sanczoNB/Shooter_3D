#include "Strzal.h"


Strzal::Strzal()
{
	rot_x = (float)(M_PI_2);
	shape_scale = 0.02f;
	cyl_hei = 1.0f;
	shape_color = System::Drawing::Color::Gold.ToArgb();
	shape_position = Vector3(0, 0, 0);
}

Strzal::Strzal(const Vector3& position)
{
	rot_x = (float)(M_PI_2);
	shape_scale = 0.02f;
	cyl_hei = 0.5f;
	shape_color = System::Drawing::Color::Gold.ToArgb();
	shape_position = position;
	shape_position.Z -= cyl_hei / 2;
	Funkcja_konstruktora();
}

Strzal::~Strzal()
{
}


//array<CustomVertex::PositionNormalColored>^ Strzal::CreateShape(){
//	array<CustomVertex::PositionNormalColored>^ cylinder = gcnew array<CustomVertex::PositionNormalColored>(731);
//	int counter = 0;
//	float add = -shape_scale*1.0f;
//	float cyl_height = cyl_hei;
//
//
//	array<Vector3>^ v1 = gcnew array<Vector3>(731);
//	points_x[0] = shape_position.X;
//	points_y[0] = shape_position.Y - 0.5f*cyl_height*sinf(rot_x + M_PI_2);
//	points_z[0] = shape_position.Z - 0.5f*cyl_height*cosf(rot_x + M_PI_2);
//	counter = 1;
//	v1[0] = Vector3(points_x[0], points_y[0], points_z[0]);
//
//	for (double angle = 0; angle <= 2 * M_PI + M_PI_2 / 45; angle += M_PI_2 / 45){ //czyli co 2 stopnie kolejny bok trójk¹ta
//		points_x[counter] = shape_position.X + add*cosf(angle);
//		points_y[counter] = shape_position.Y - 0.5f*cyl_height*sinf(rot_x + M_PI_2) + add*sinf(angle)*sinf(rot_x);
//		points_z[counter] = shape_position.Z - 0.5f*cyl_height*cosf(rot_x + M_PI_2) + add*sinf(angle)*cosf(rot_x);
//		v1[counter++] = Vector3(points_x[counter], points_y[counter], points_z[counter]);
//	}
//	int cyl_count = 0;
//	for (int i = 0; i < counter; i++){
//		cylinder[i++] = CustomVertex::PositionNormalColored(v1[0], v1[0], shape_color);
//		cylinder[i] = CustomVertex::PositionNormalColored(v1[i], v1[i], shape_color);
//		cyl_count = i;
//	}
//	//zakoñczone sk³adanie dolnej podstawy
//
//
//	for (double angle = 0; angle <= 2 * M_PI + M_PI_2 / 45; angle += M_PI_2 / 45){ //czyli co 2 stopnie kolejny bok trójk¹ta
//		points_x[counter] = shape_position.X + add*cos(angle);
//		points_y[counter] = shape_position.Y + 0.5f*cyl_height*sinf(rot_x + M_PI_2) + add*sinf(angle)*sinf(rot_x);
//		points_z[counter] = shape_position.Z + 0.5f*cyl_height*cosf(rot_x + M_PI_2) + add*sinf(angle)*cosf(rot_x);
//		v1[counter++] = Vector3(points_x[counter], points_y[counter], points_z[counter]);
//		points_x[counter] = shape_position.X + add*cos(angle);
//		points_y[counter] = shape_position.Y - 0.5f*cyl_height*sinf(rot_x + M_PI_2) + add*sinf(angle)*sinf(rot_x);
//		points_z[counter] = shape_position.Z - 0.5f*cyl_height*cosf(rot_x + M_PI_2) + add*sinf(angle)*cosf(rot_x);
//		v1[counter++] = Vector3(points_x[counter], points_y[counter], points_z[counter]);
//	}
//	int ii = cyl_count;
//	while (ii <counter){
//		cylinder[ii++] = CustomVertex::PositionNormalColored(v1[ii], v1[ii], shape_color);
//		cylinder[ii++] = CustomVertex::PositionNormalColored(v1[ii], v1[ii], shape_color);
//	}
//	//zakoñczono sk³adanie powierzchnii walcowej
//
//	////przejœcie do górnej podstawy
//	//cylinder[ii] = CustomVertex::PositionNormalColored(v1[ii-1], v1[ii-1], shape_color);
//	//cylinder[ii+1] = CustomVertex::PositionNormalColored(v1[ii - 1], v1[ii - 1], shape_color);
//
//	cyl_count = counter;
//	ii = 0;
//	while (ii<183){
//		v1[counter++] = Vector3(points_x[ii], points_y[ii] + cyl_height*sinf(rot_x + M_PI_2), points_z[ii] + cyl_height*cosf(rot_x + M_PI_2));
//		ii++;
//	}
//	Vector3 v2 = Vector3(points_x[0], points_y[0] + sinf(rot_x + M_PI_2)*cyl_height, points_z[0] + cosf(rot_x + M_PI_2)*cyl_height);
//	for (int i = cyl_count; i < counter; i++){
//		cylinder[i++] = CustomVertex::PositionNormalColored(v2, v2, shape_color);
//		cylinder[i] = CustomVertex::PositionNormalColored(v1[i], v1[i], shape_color);
//	}
//	//zakoñczone sk³adanie dolnej podstawy
//
//	return cylinder;
//}