#include "Player_Ship.h"

using namespace System;
using namespace System::Drawing;
using namespace Microsoft::DirectX;
using namespace Microsoft::DirectX::Direct3D;

Player_Ship::Player_Ship()
{
	points_x = gcnew array<FLOAT>(17);
	points_y = gcnew array<FLOAT>(17);
	points_z = gcnew array<FLOAT>(17);
	v1 = gcnew array<Vector3>(17);
	position = Vector3(0, 0, 0);
	shape_position = position;
	color = Color::Red.ToArgb();
	ship_scale = 1.0f;
	AssignColors(0);
	intersect_pts = gcnew array<Vector3>(2);
	ship=create_ship();
	shape_ptr = ship;
}

Player_Ship::Player_Ship(const Vector3& pos){
	points_x = gcnew array<FLOAT>(17);
	points_y = gcnew array<FLOAT>(17);
	points_z = gcnew array<FLOAT>(17);
	v1 = gcnew array<Vector3>(17);

	position = pos;
	CheckShipPosition();
	shape_position = position;
	color = Color::Red.ToArgb();
	ship_scale = 1.0f;
	AssignColors(0);
	intersect_pts = gcnew array<Vector3>(2);
	ship=create_ship();
	shape_ptr = ship;
}

Player_Ship::Player_Ship(const Vector3& pos, const float& scale){
	points_x = gcnew array<FLOAT>(17);
	points_y = gcnew array<FLOAT>(17);
	points_z = gcnew array<FLOAT>(17);
	v1 = gcnew array<Vector3>(17);

	position = pos;
	CheckShipPosition();
	shape_position = position;
	color = Color::Red.ToArgb();
	ship_scale = scale;
	AssignColors(0);
	intersect_pts = gcnew array<Vector3>(2);
	ship = create_ship();
	shape_ptr = ship;
}

Player_Ship::Player_Ship(const Vector3& pos, const float& scale, const int& color_theme){
	points_x = gcnew array<FLOAT>(17);
	points_y = gcnew array<FLOAT>(17);
	points_z = gcnew array<FLOAT>(17);
	v1 = gcnew array<Vector3>(17);
	
	position = pos;
	CheckShipPosition();
	shape_position = position;
	color = Color::Red.ToArgb();
	ship_scale = scale;
	AssignColors(color_theme);
	intersect_pts = gcnew array<Vector3>(2);
	ship = create_ship();
	shape_ptr = ship;
}

Player_Ship::~Player_Ship(){

}

array<CustomVertex::PositionNormalColored>^ Player_Ship::CreateShape(){ //Dostêp do funkcji przesuniêcia statku gracza wzd³u¿ kierunku Z mo¿na uzyskaæ z klasy Bryla_3D_bez_punktow
	position = shape_position;
	ship = create_ship();
	shape_ptr = ship;
	return ship;
}

array<CustomVertex::PositionNormalColored>^ Player_Ship::create_ship(){

	AssignPointsCoordinates();
	int count_points = 0;

	//points_x[0] = 0;
	//points_y[0] = 0.05;
	//points_z[0] = 1.9;
	//points_x[1] = -0.05;
	//points_y[1] = 0;
	//points_z[1] = 1.8;
	//points_x[2] = -0.45;
	//points_y[2] = 0;
	//points_z[2] = 0.7;
	//points_x[3] = -0.25;
	//points_y[3] = 0;
	//points_z[3] = 0;
	//points_x[4] = 0.25;
	//points_y[4] = 0;
	//points_z[4] = 0;
	//points_x[5] = 0.45;
	//points_y[5] = 0;
	//points_z[5] = 0.7;
	//points_x[6] = 0.05;
	//points_y[6] = 0;
	//points_z[6] = 1.8;
	//points_x[7] = -0.05;
	//points_y[7] = 0.1;
	//points_z[7] = 1.8;
	//points_x[8] = -0.45;
	//points_y[8] = 0.1;
	//points_z[8] = 0.7;
	//points_x[9] = -0.25;
	//points_y[9] = 0.1;
	//points_z[9] = 0;
	//points_x[10] = 0.25;
	//points_y[10] = 0.1;
	//points_z[10] = 0;
	//points_x[11] = 0.45;
	//points_y[11] = 0.1;
	//points_z[11] = 0.7;
	//points_x[12] = 0.05;
	//points_y[12] = 0.1;
	//points_z[12] = 1.8;
	//points_x[13] = -0.2;
	//points_y[13] = 0.3;
	//points_z[13] = 1.2;
	//points_x[14] = -0.15;
	//points_y[14] = 0.4;
	//points_z[14] = 0.9;
	//points_x[15] = 0.15;
	//points_y[15] = 0.4;
	//points_z[15] = 0.9;
	//points_x[16] = 0.2;
	//points_y[16] = 0.3;
	//points_z[16] = 1.2;
	//
	//for (int i = 0; i < 17; i++){
	//	v1[i] = Vector3(points_x[i]+0.5, points_y[i]+0.0, points_z[i]+0.0);
	//}
	//
	//array<CustomVertex::PositionNormalColored>^ sh = gcnew array<CustomVertex::PositionNormalColored>(90);
	//
	//for (int i = 0; i < sh->Length; i++)
	//	sh[i] = CustomVertex::PositionNormalColored();

	////nosek - œciana prawa (od przodu)
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], Color::Green.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[1], v1[1], Color::Green.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[0], v1[0], Color::Green.ToArgb());
	//
	////nosek - œciana dolna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[6], v1[6], Color::Green.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[0], v1[0], Color::Green.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[1], v1[1], Color::Green.ToArgb());
	//
	////podstawa - lewa czêœæ œrodka
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[6], v1[6], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[1], v1[1], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color);
	//
	////podstawa - prawa czêœæ œrodka
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[1], v1[1], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[3], v1[3], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color);
	//
	////podstawa - prawa czêœæ skrajna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[2], v1[2], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[3], v1[3], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[1], v1[1], color);
	//
	////bok - przód prawy, czêœæ dolna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[2], v1[2], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[1], v1[1], color);
	//
	////bok - przód prawy, czêœæ górna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[8], v1[8], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[2], v1[2], color);
	//
	////œrodek - prawy przod
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[13], v1[13], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[8], v1[8], color);
	//
	////gora - czêœæ przednia, prawa
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[13], v1[13], color);
	//
	////gora - szyba, czêœæ prawa
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], Color::Blue.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], Color::Blue.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[13], v1[13], Color::Blue.ToArgb());
	//
	////œrodek - prawy tyl górny
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[13], v1[13], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[8], v1[8], color);
	//
	////œrodek - prawy tyl dolny
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[8], v1[8], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color);
	//
	//////bok - œrodek prawy, czêœæ górna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[2], v1[2], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[8], v1[8], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color);
//
	//////bok - œrodek prawy, czêœæ dolna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[2], v1[2], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[3], v1[3], color);
//
	//////bok - tyl, czêœæ dolna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[3], v1[3], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color);
//
	//////bok - tyl, czêœæ górna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[10], v1[10], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color);
	//
	//////œrodek - tyl dolny
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[10], v1[10], color);
	//
	//////œrodek - tyl górny
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[15], v1[15], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[10], v1[10], color);
//
	////góra - szyba, czêœæ lewa
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], Color::Blue.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], Color::Blue.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[15], v1[15], Color::Blue.ToArgb());
//
	////gora - czêœæ przednia, lewa
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color);
	//
//
	////œrodek - lewy przód
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color);
//
	////œrodek - lewy tyl górny
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[15], v1[15], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color);
//
	////œrodek - lewy tyl dolny
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[10], v1[10], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[15], v1[15], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color);
//
	////bok - œrodek lewy, czêœæ górna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[10], v1[10], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color);
//
	////bok - œrodek lewy, czêœæ dolna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[5], v1[5], color);
//
	////podstawa - lewa czesc skrajna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[5], v1[5], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[6], v1[6], color);
	//
	////bok - przód lewy, czêœæ dolna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[5], v1[5], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[6], v1[6], color);
//
	////bok - przód lewy, czêœæ górna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], color);
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[6], v1[6], color);
//
	////nosek - œciana lewa (od przodu)
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], Color::Green.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[0], v1[0], Color::Green.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[6], v1[6], Color::Green.ToArgb());
//
	////nosek - œciana gorna
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], Color::Green.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], Color::Green.ToArgb());
	//sh[count_points++] = CustomVertex::PositionNormalColored(v1[0], v1[0], Color::Green.ToArgb());

	for (int i = 0; i < 17; i++){
		v1[i].X = points_x[i];
		v1[i].Y = points_y[i],
		v1[i].Z = points_z[i];
	}

	array<CustomVertex::PositionNormalColored>^ sh2 = gcnew array<CustomVertex::PositionNormalColored>(82);
	count_points = 0;

	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], color_for_side_front_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color_for_side_front_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color_for_side_front_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color_for_side_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color_for_side_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[15], v1[15], color_for_side_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color_for_side_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[10], v1[10], color_for_side_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[10], v1[10], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[15], v1[15], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color_for_side_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], color_for_side_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[8], v1[8], color_for_side_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[13], v1[13], color_for_side_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[8], v1[8], color_for_side_front_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[13], v1[13], color_for_side_front_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color_for_side_front_parts);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[13], v1[13], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color_for_up_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[5], v1[5], color_for_up_part);
	//podstawa
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[5], v1[5], color_for_bottom);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color_for_bottom);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[6], v1[6], color_for_bottom);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[3], v1[3], color_for_bottom);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[1], v1[1], color_for_bottom);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[2], v1[2], color_for_bottom);
	//boki
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[1], v1[1], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[2], v1[2], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[8], v1[8], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[8], v1[8], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[3], v1[3], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[3], v1[3], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[3], v1[3], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[8], v1[8], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[2], v1[2], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[2], v1[2], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[3], v1[3], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[9], v1[9], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[10], v1[10], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[10], v1[10], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[4], v1[4], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[5], v1[5], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[5], v1[5], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[10], v1[10], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[5], v1[5], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[6], v1[6], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[6], v1[6], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[11], v1[11], color_for_down_part);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], color_for_down_part);
	//nosek
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], color_for_nose);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[6], v1[6], color_for_nose);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[0], v1[0], color_for_nose);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[1], v1[1], color_for_nose);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color_for_nose);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[7], v1[7], color_for_nose);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[0], v1[0], color_for_nose);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], color_for_nose);
	//szybka
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[12], v1[12], color_for_window);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color_for_window);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[16], v1[16], color_for_window);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[13], v1[13], color_for_window);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[15], v1[15], color_for_window);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], color_for_window);
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], Color::White.ToArgb());			//
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], Color::White.ToArgb());			//  Zakoñczenie statku, ¿eby nie wyrysowywa³ siê kolejny trójk¹t
	sh2[count_points++] = CustomVertex::PositionNormalColored(v1[14], v1[14], Color::White.ToArgb());			//
	
	length_of_ship = count_points - 1;
	return sh2;
}

Void Player_Ship::Move_Ship(const Vector3& vector){
	
	if (position.Y + vector.Y <= 2.8f && position.Y+vector.Y>=0.0f)
		position.Y += vector.Y;
	if (position.X + vector.X >= -2.5f && position.X + vector.X<=2.5f)	
		position.X += vector.X;
	
	position.Z += vector.Z;
	ship = create_ship();
}

Void Player_Ship::MoveShipWithKeys(){
	ship = create_ship();
}

INT Player_Ship::Length(){
	return length_of_ship;
}

array<CustomVertex::PositionNormalColored>^ Player_Ship::Get_ship(){
	return ship;
}

INT Player_Ship::Get_ship_color(){
	return color;
}

Vector3 Player_Ship::GetNosePosition(){
	return Vector3(points_x[0],points_y[0],points_z[0]);
}

void Player_Ship::Act_on_key_down(System::Windows::Forms::PreviewKeyDownEventArgs^ e){
	if (e->KeyCode == move_up){
		up_key_pressed = 1;
	}
	else if (e->KeyCode == move_down){
		down_key_pressed = 1;
	}
	else if (e->KeyCode == move_left){
		left_key_pressed = 1;
	}
	else if (e->KeyCode == move_right){
		right_key_pressed = 1;
	}
}

void Player_Ship::Act_on_key_pressed(){
	float ship_type = 0.0f;
	if (ship_pointing_direction == -1)
		ship_type = 0.010f;

	if (up_key_pressed == 1){
		position.Y += (ship_movement_interval - ship_type);
		if (position.Y > 2.8f)
			position.Y = 2.8f;
	}
	if (down_key_pressed == 1){
		position.Y -= (ship_movement_interval - ship_type);
		if (position.Y<0.0f)
			position.Y = 0.0f;
	}
	if (left_key_pressed == 1){
		position.X -= (ship_movement_interval - ship_type);
		if (position.X < -2.5f)
			position.X = -2.50f;
	}
	if (right_key_pressed == 1){
		position.X += (ship_movement_interval - ship_type);
		if (position.X>2.5f)
			position.X = 2.50f;
	}
	if (up_key_pressed==1 || down_key_pressed==1 || right_key_pressed==1|| left_key_pressed==1)
		MoveShipWithKeys();
	 
}

void Player_Ship::Act_on_key_up(System::Windows::Forms::KeyEventArgs^ e){
	if (e->KeyCode == move_up){
		up_key_pressed = 0;
	}
	else if (e->KeyCode == move_down){
		down_key_pressed = 0;
	}
	else if (e->KeyCode == move_left){
		left_key_pressed = 0;
	}
	else if (e->KeyCode == move_right){
		right_key_pressed = 0;
	}
}

void Player_Ship::AssignPointsCoordinates(){

	points_x[0] = 0.0f;
	points_y[0] = 0.05f;
	points_z[0] = 2.0f*ship_pointing_direction;

	points_x[1] = -0.1f;
	points_y[1] = 0.0f;
	points_z[1] = 1.8f*ship_pointing_direction;

	points_x[2] = -0.45f;
	points_y[2] = 0.0f;
	points_z[2] = 0.7f*ship_pointing_direction;

	points_x[3] = -0.25f;
	points_y[3] = 0.0f;
	points_z[3] = 0.0f*ship_pointing_direction;

	points_x[4] = 0.25f;
	points_y[4] = 0.0f;
	points_z[4] = 0.0f*ship_pointing_direction;

	points_x[5] = 0.45f;
	points_y[5] = 0.0f;
	points_z[5] = 0.7f*ship_pointing_direction;

	points_x[6] = 0.1f;
	points_y[6] = 0.0f;
	points_z[6] = 1.8f*ship_pointing_direction;

	points_x[7] = -0.1f;
	points_y[7] = 0.1f;
	points_z[7] = 1.8f*ship_pointing_direction;

	points_x[8] = -0.45f;
	points_y[8] = 0.1f;
	points_z[8] = 0.7f*ship_pointing_direction;

	points_x[9] = -0.25f;
	points_y[9] = 0.1f;
	points_z[9] = 0.0f*ship_pointing_direction;

	points_x[10] = 0.25f;
	points_y[10] = 0.1f;
	points_z[10] = 0.0f*ship_pointing_direction;

	points_x[11] = 0.45f;
	points_y[11] = 0.1f;
	points_z[11] = 0.7f*ship_pointing_direction;

	points_x[12] = 0.1f;
	points_y[12] = 0.1f;
	points_z[12] = 1.8f*ship_pointing_direction;

	points_x[13] = -0.25f;
	points_y[13] = 0.3f;
	points_z[13] = 0.75f*ship_pointing_direction;

	points_x[14] = -0.15f;
	points_y[14] = 0.35f;
	points_z[14] = 0.3f*ship_pointing_direction;

	points_x[15] = 0.15f;
	points_y[15] = 0.35f;
	points_z[15] = 0.3f*ship_pointing_direction;

	points_x[16] = 0.25f;
	points_y[16] = 0.3f;
	points_z[16] = 0.75f*ship_pointing_direction;

	for (int i = 0; i < 17; i++){
		points_x[i] = points_x[i] * ship_scale +  position.X;
		points_y[i] = points_y[i] * ship_scale +  position.Y;
		points_z[i] = points_z[i] * ship_scale +  position.Z;
		//intersect_pts[i] = Vector3(points_x[i], points_y[i], points_z[i]);
	}

	shape_position = position;
	intersect_pts[0] = Vector3(position.X, position.Y, position.Z);
	intersect_pts[1]=Vector3(0.45f*ship_scale, 0.35f*ship_scale, 2.0f*ship_scale*ship_pointing_direction);
	SetIntersectionPoints(intersect_pts);
}

void Player_Ship::AssignColors(const int& theme_number){
	switch (theme_number){
		case 0: {
			color_for_bottom = Color::Black.ToArgb();
			color_for_window = Color::DarkBlue.ToArgb();
			color_for_down_part = Color::Black.ToArgb();
			color_for_side_parts = Color::Red.ToArgb();
			color_for_side_front_parts = Color::Red.ToArgb();
			color_for_up_part = Color::DarkViolet.ToArgb();
			color_for_nose = Color::Black.ToArgb();
		}break;
		case 1: {
			color_for_bottom = Color::Gray.ToArgb();
			color_for_window = Color::SkyBlue.ToArgb();
			color_for_down_part = Color::Goldenrod.ToArgb();
			color_for_side_parts = Color::Green.ToArgb();
			color_for_side_front_parts = Color::Violet.ToArgb();
			color_for_up_part = Color::Khaki.ToArgb();
			color_for_nose = Color::Gold.ToArgb();
		}break;
		case 2: {
			/*color_for_bottom = Color::Black.ToArgb();
			color_for_window = Color::Red.ToArgb();
			color_for_down_part = Color::DarkViolet.ToArgb();
			color_for_side_parts = Color::DarkSlateGray.ToArgb() + 20;
			color_for_side_front_parts = Color::DarkSlateGray.ToArgb();
			color_for_up_part = Color::DarkSlateBlue.ToArgb();
			color_for_nose = Color::Crimson.ToArgb();*/
			color_for_bottom = Color::Black.ToArgb();
			color_for_window = Color::Black.ToArgb()+55;
			color_for_down_part = Color::Black.ToArgb();
			color_for_side_parts = Color::Black.ToArgb()+20;
			color_for_side_front_parts = Color::Black.ToArgb()+25;
			color_for_up_part = Color::Black.ToArgb() + 15;
			color_for_nose = Color::Black.ToArgb()+55;
		}break;
		case 3: {
			color_for_bottom = Color::Black.ToArgb();
			color_for_window = Color::Red.ToArgb();
			color_for_down_part = Color::DarkViolet.ToArgb();
			color_for_side_parts = Color::DarkSlateGray.ToArgb()+20;
			color_for_side_front_parts = Color::DarkSlateGray.ToArgb();
			color_for_up_part = Color::DarkSlateBlue.ToArgb();
			color_for_nose = Color::Crimson.ToArgb();
		}break;
	}
}

array<CustomVertex::PositionNormalColored>^ Player_Ship::ChangeObjectColor(const int& kol){
	AssignColors(3);
	return create_ship();
}

void Player_Ship::CheckShipPosition(){
	if (position.Y > 2.8f)
		position.Y = 2.8f;
	else if (position.Y < 0.0f)
		position.Y = 0.0f;
	else
		position.Y = position.Y;
	if (abs(position.X) > 2.5f)
		if (position.X < 0)
			position.X = -2.5f;
		else
			position.X = 2.5f;
	else
		position.X = position.X;

	if (position.Z!=0)
		position.Z = 0.0f;	// pos.Z;
}