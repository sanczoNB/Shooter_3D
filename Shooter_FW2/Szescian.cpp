#include "Szescian.h"

using namespace System::Drawing;

Szescian::Szescian(){
	shape_scale = 1.0f;
	shape_color = Drawing::Color::Brown.ToArgb();
	shape_position = Vector3(0, 0, 0);
	points_x = gcnew array < FLOAT >(8);
	points_y = gcnew array < FLOAT >(8);
	points_z = gcnew array < FLOAT >(8);
	shape_ptr = CreateShape();
}

Szescian::Szescian(const float& cube_scale){
	shape_scale = cube_scale;
	shape_color = Color::Blue.ToArgb();
	shape_position = Vector3(0, 1, 2);
	points_x = gcnew array < FLOAT >(8);
	points_y = gcnew array < FLOAT >(8);
	points_z = gcnew array < FLOAT >(8);
	shape_ptr = CreateShape();
}

Szescian::Szescian(const float& cube_scale, const int& cube_color){
	shape_scale = cube_scale;
	shape_color = cube_color;
	shape_position = Vector3(0, 1, 2);
	points_x = gcnew array < FLOAT >(8);
	points_y = gcnew array < FLOAT >(8);
	points_z = gcnew array < FLOAT >(8);
	shape_ptr = CreateShape();
}

Szescian::Szescian(const float& cube_scale, const int& cube_color, const Vector3& cube_position){
	shape_scale = cube_scale;
	shape_color = cube_color;
	shape_position = cube_position;
	points_x = gcnew array < FLOAT >(8);
	points_y = gcnew array < FLOAT >(8);
	points_z = gcnew array < FLOAT >(8);
	shape_ptr = CreateShape();
}

Szescian::~Szescian()
{
}

array<CustomVertex::PositionNormalColored>^ Szescian::CreateShape(){
	array<CustomVertex::PositionNormalColored>^ cube = gcnew array<CustomVertex::PositionNormalColored>(37);
	int counter = 0;
	float add= shape_scale*0.5f;
	//
	points_x[counter] = shape_position.X + add;
	points_y[counter] = shape_position.Y - add;
	points_z[counter++] = shape_position.Z + add;

	points_x[counter] = shape_position.X - add;
	points_y[counter] = shape_position.Y - add;
	points_z[counter++] = shape_position.Z + add;

	points_x[counter] = shape_position.X + add;
	points_y[counter] = shape_position.Y + add;
	points_z[counter++] = shape_position.Z + add;

	points_x[counter] = shape_position.X - add;
	points_y[counter] = shape_position.Y + add;
	points_z[counter++] = shape_position.Z + add;

	points_x[counter] = shape_position.X - add;
	points_y[counter] = shape_position.Y + add;
	points_z[counter++] = shape_position.Z - add;

	points_x[counter] = shape_position.X - add;
	points_y[counter] = shape_position.Y - add;
	points_z[counter++] = shape_position.Z - add;

	points_x[counter] = shape_position.X + add;
	points_y[counter] = shape_position.Y + add;
	points_z[counter++] = shape_position.Z - add;

	points_x[counter] = shape_position.X + add;
	points_y[counter] = shape_position.Y - add;
	points_z[counter++] = shape_position.Z - add;

	counter = 0;
	array<Vector3>^ vectors = gcnew array<Vector3>(8);
	for (int i = 0; i < 8; i++){
		vectors[i] = Vector3(points_x[i], points_y[i], points_z[i]);
		//cube[counter++] = CustomVertex::PositionNormalColored(vectors[i], -vectors[i], shape_color);
	}

	//cube[counter++] = CustomVertex::PositionNormalColored(vectors[7], vectors[7], shape_color);
	//cube[counter++] = CustomVertex::PositionNormalColored(vectors[3], vectors[3], shape_color);
	//cube[counter++] = CustomVertex::PositionNormalColored(vectors[3], vectors[3], shape_color);
	//cube[counter++] = CustomVertex::PositionNormalColored(vectors[5], vectors[5], shape_color);
	//cube[counter++] = CustomVertex::PositionNormalColored(vectors[1], vectors[1], shape_color);
	//cube[counter++] = CustomVertex::PositionNormalColored(vectors[7], vectors[7], shape_color);
	//cube[counter++] = CustomVertex::PositionNormalColored(vectors[0], vectors[0], shape_color);
	//cube[counter++] = CustomVertex::PositionNormalColored(vectors[6], vectors[6], shape_color);
	//cube[counter++] = CustomVertex::PositionNormalColored(vectors[2], vectors[2], shape_color);
	//cube[counter++] = CustomVertex::PositionNormalColored(vectors[4], vectors[4], shape_color);

	//Lista trójk¹tów szeœcianu
	//tylna sciana, gora
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[1], vectors[1], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[2], vectors[2], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[3], vectors[3], shape_color);
	//tylna sciana, dol
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[1], vectors[1], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[0], vectors[0], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[2], vectors[2], shape_color);
	//lewa sciana dol
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[3], vectors[3], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[5], vectors[5], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[1], vectors[1], shape_color);
	//lewa sciana, gora
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[3], vectors[3], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[4], vectors[4], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[5], vectors[5], shape_color);
	//prawa sciana gora
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[6], vectors[6], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[2], vectors[2], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[0], vectors[0], shape_color);
	//prawa sciana dol
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[6], vectors[6], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[0], vectors[0], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[7], vectors[7], shape_color);
	//przednia sciana dol
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[5], vectors[5], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[6], vectors[6], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[7], vectors[7], shape_color);
	//przednia sciana gora
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[5], vectors[5], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[4], vectors[4], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[6], vectors[6], shape_color);
	//gorna sciana przod
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[6], vectors[6], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[4], vectors[4], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[2], vectors[2], shape_color);
	//gorna sciana tyl
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[4], vectors[4], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[3], vectors[3], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[2], vectors[2], shape_color);
	//dolna sciana tyl
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[0], vectors[0], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[1], vectors[1], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[5], vectors[5], shape_color);
	//dolna sciana przod
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[0], vectors[0], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[5], vectors[5], shape_color);
	cube[counter++] = CustomVertex::PositionNormalColored(vectors[7], vectors[7], shape_color);

	return cube;
}

//Vector3 Szescian::GetPosition(){
//	return shape_position;
//}

//Void Szescian::MoveShape(const Vector3& vector){
//	shape_position += vector;
//	shape_ptr = CreateShape();
//}