#include "Czworoscian.h"


Czworoscian::Czworoscian(){
	shape_scale = 1.0f;
	shape_color = Drawing::Color::Black.ToArgb();
	shape_position = Vector3(0, 0, 0);
	shape_ptr = CreateShape();
}

Czworoscian::Czworoscian(const float& tethraedron_scale){
	shape_scale = tethraedron_scale;
	shape_color = Drawing::Color::Black.ToArgb();
	shape_position = Vector3(0, 0, 0);
	shape_ptr = CreateShape();
}

Czworoscian::Czworoscian(const float& tethraedron_scale, const int& tethraedron_color){
	shape_scale = tethraedron_scale;
	shape_color = tethraedron_color;
	shape_position = Vector3(0, 0, 0);
	shape_ptr = CreateShape();
}

Czworoscian::Czworoscian(const float& tethraedron_scale, const int& tethraedron_color, const Vector3& tethraedron_position){
	shape_scale = tethraedron_scale;
	shape_color = tethraedron_color;
	shape_position = tethraedron_position;
	shape_ptr = CreateShape();
}


Czworoscian::~Czworoscian(){

}

array<CustomVertex::PositionNormalColored>^ Czworoscian::CreateShape(){
	points_x = gcnew array < FLOAT >(4);
	points_y = gcnew array < FLOAT >(4);
	points_z = gcnew array < FLOAT >(4);

	array<CustomVertex::PositionNormalColored>^ tethraedron = gcnew array<CustomVertex::PositionNormalColored>(12);

	int counter = 0;
	float add = shape_scale*0.5f;
	//
	points_x[counter] = shape_position.X + add;
	points_y[counter] = shape_position.Y - add;
	points_z[counter++] = shape_position.Z - add;

	points_x[counter] = shape_position.X - add;
	points_y[counter] = shape_position.Y - add;
	points_z[counter++] = shape_position.Z - add;

	points_x[counter] = shape_position.X;
	points_y[counter] = shape_position.Y - add;
	points_z[counter++] = shape_position.Z + add;

	points_x[counter] = shape_position.X;
	points_y[counter] = shape_position.Y + add;
	points_z[counter++] = shape_position.Z;

	counter = 0;
	array<Vector3>^ vectors = gcnew array<Vector3>(4);
	for (int i = 0; i < 4; i++){
		vectors[i] = Vector3(points_x[i], points_y[i], points_z[i]);
	}

	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[1], vectors[1], shape_color);
	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[0], vectors[0], shape_color);
	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[2], vectors[2], shape_color);

	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[0], vectors[0], shape_color);
	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[1], vectors[1], shape_color);
	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[3], vectors[3], shape_color);
	
	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[1], vectors[1], shape_color);
	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[2], vectors[2], shape_color);
	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[3], vectors[3], shape_color);

	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[3], vectors[3], shape_color);
	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[2], vectors[2], shape_color);
	tethraedron[counter++] = CustomVertex::PositionNormalColored(vectors[0], vectors[0], shape_color);

	return tethraedron;
}
