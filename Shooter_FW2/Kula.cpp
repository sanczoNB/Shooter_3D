#include "Kula.h"

using namespace System;
using namespace System::Drawing;
using namespace Microsoft::DirectX;
using namespace Microsoft::DirectX::Direct3D;


Kula::Kula(){
	r = 1;
	position = Vector3(0, 0, 0);
	kolor_kuli = Color::BlueViolet.ToArgb();

	shape_position = Vector3(0, 0, 0);
	shape_color = Color::BlueViolet.ToArgb();

	//kula=utworz_kule();
	shape_ptr = CreateShape();
}

Kula::Kula(FLOAT R, Vector3 pos, INT color){
	r = R;
	position = pos;
	kolor_kuli = color;

	shape_position = pos;
	shape_color = color;

	//kula = utworz_kule();
	shape_ptr = CreateShape();
}

Kula::Kula(Kula^ k){
	r = k->Get_r();
	position = k->Get_position();
	shape_position = k->GetPosition();
	shape_color = k->GetShapeColor();

	kolor_kuli = k->Get_kolor_kuli();
	//kula = k->Get_kula();
	shape_ptr = k->GetShape();
//	"Konstruktor kopiujacy
}

Kula::~Kula()
{
}

array<CustomVertex::PositionNormalColored>^ Kula::CreateShape(){
	return shape_ptr = utworz_kule();
}

array<CustomVertex::PositionNormalColored>^ Kula::utworz_kule(){
	
	points_x = gcnew array<FLOAT>(3321);
	points_y = gcnew array<FLOAT>(3321);
	points_z = gcnew array<FLOAT>(3321);

	int count_points = 0;

	for (float fi = 0; fi <= (float)(2 * M_PI + M_PI / 40); fi += (float)(M_PI / 40)){
		for (float eta = 0; eta <= (float)(M_PI + M_PI / 40); eta += (float)(M_PI / 40)){
			points_x[count_points] = (r*cosf(fi)*sinf(eta)) + shape_position.X;	//tutaj równanie
			points_y[count_points] = (r*sinf(fi)*sinf(eta)) + shape_position.Y;	//tutaj równanie
			points_z[count_points] = r*cosf(eta) + shape_position.Z;				//tutaj równanie

			count_points++;
		}
	}

	array<CustomVertex::PositionNormalColored>^ kl = gcnew array<CustomVertex::PositionNormalColored>(19675);

	int sphere_counter = 0;
	count_points = 0;

	while (count_points<points_x->Length - 42){
		kl[sphere_counter + 2] = CustomVertex::PositionNormalColored(Vector3(points_x[count_points], points_y[count_points], points_z[count_points]), -Vector3(points_x[count_points], points_y[count_points], points_z[count_points]), shape_color);
		kl[sphere_counter + 1] = CustomVertex::PositionNormalColored(Vector3(points_x[count_points + 41], points_y[count_points + 41], points_z[count_points + 41]), -Vector3(points_x[count_points + 41], points_y[count_points + 41], points_z[count_points + 41]), shape_color);

		kl[sphere_counter + 5] = CustomVertex::PositionNormalColored(Vector3(points_x[count_points + 41], points_y[count_points + 41], points_z[count_points + 41]), -Vector3(points_x[count_points + 41], points_y[count_points + 41], points_z[count_points + 41]), shape_color);

		count_points++;
		kl[sphere_counter] = CustomVertex::PositionNormalColored(Vector3(points_x[count_points], points_y[count_points], points_z[count_points]), -Vector3(points_x[count_points], points_y[count_points], points_z[count_points]), shape_color);
		kl[sphere_counter + 4] = CustomVertex::PositionNormalColored(Vector3(points_x[count_points], points_y[count_points], points_z[count_points]), -Vector3(points_x[count_points], points_y[count_points], points_z[count_points]), shape_color);
		kl[sphere_counter + 3] = CustomVertex::PositionNormalColored(Vector3(points_x[count_points + 41], points_y[count_points + 41], points_z[count_points + 41]), -Vector3(points_x[count_points + 41], points_y[count_points + 41], points_z[count_points + 41]), shape_color);
		
		//for (int j = 0 + sphere_counter; j < sphere_counter + 6; j++){
		//	if ()
		//}
		sphere_counter += 6;
	}
	kl[19674] = CustomVertex::PositionNormalColored();
	/*for (sphere_counter; sphere_counter < kl->Length;sphere_counter++){
		kl[sphere_counter] = CustomVertex::PositionNormalColored(Vector3(0,0,0), Vector3(0,0,0), kolor_kuli);
	}*/
	return kl;
}

array<CustomVertex::PositionNormalColored>^ Kula::Get_kula(){
	//return kula;
	return shape_ptr;
}

FLOAT Kula::Get_r(){
	return r;
}

Vector3 Kula::Get_position(){
	return position;
}

INT Kula::Get_kolor_kuli(){
	return kolor_kuli;
}

INT Kula::Length(){
	//return kula->Length;
	return shape_ptr->Length;
}

Void Kula::Move_Kula(const Vector3& vector){
	position += vector;
	//kula = utworz_kule();
	shape_ptr = CreateShape();
}
