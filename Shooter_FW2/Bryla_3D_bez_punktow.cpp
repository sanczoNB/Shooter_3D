#include "Bryla_3D_bez_punktow.h"


Bryla_3D_bez_punktow::Bryla_3D_bez_punktow()
{
}


Bryla_3D_bez_punktow::~Bryla_3D_bez_punktow()
{
}

array<CustomVertex::PositionNormalColored>^ Bryla_3D_bez_punktow::GetShape(){
	return shape_ptr;
}

INT Bryla_3D_bez_punktow::GetShapePtrLength(){
	INT lngth = 0;
	if (shape_ptr != nullptr)
		lngth = shape_ptr->Length-1;

	return lngth;
}

array<CustomVertex::PositionNormalColored>^ Bryla_3D_bez_punktow::CreateShape(){
	return this->shape_ptr;
}

array<CustomVertex::PositionNormalColored>^ Bryla_3D_bez_punktow::ChangeObjectColor(const int& kol){
	return this->shape_ptr;
}

Vector3 Bryla_3D_bez_punktow::GetPosition(){
	return this->shape_position;
}

Void Bryla_3D_bez_punktow::MoveShape(const Vector3& vector){
	shape_position += vector;
	shape_ptr = CreateShape();
}

Void Bryla_3D_bez_punktow::MoveShapeTo(const Vector3& vector){
	//this->shape_position = vector;
	//this->shape_ptr = this->CreateShape();
	shape_position = vector;
	shape_ptr = CreateShape();
}
