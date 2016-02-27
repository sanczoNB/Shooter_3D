#include "Sign_on_screen.h"


Sign_on_screen::Sign_on_screen()
{
}


Sign_on_screen::~Sign_on_screen()
{
}


void Sign_on_screen::CopyBeamElements(array<CustomVertex::PositionNormalColored>^ source, array<CustomVertex::PositionNormalColored>^ object, const int& indx){
	int counter = 0;
	for (int i = indx * 6; i < (indx + 1) * 6; i++)
		object[i] = source[counter++];
}//end of CopyBeamElements()

array<CustomVertex::PositionNormalColored>^ Sign_on_screen::CreateVerticalBeam(const Vector3& position){
	array<CustomVertex::PositionNormalColored>^ sh = gcnew array<CustomVertex::PositionNormalColored>(6);
	points_x = gcnew array<FLOAT>(6);
	points_y = gcnew array<FLOAT>(6);
	points_z = gcnew array<FLOAT>(6);

	points_x[0] = position.X + 0.05f*shape_scale;
	points_y[0] = position.Y;
	points_z[0] = position.Z;

	points_x[1] = position.X + 0.05f*shape_scale;
	points_y[1] = position.Y;
	points_z[1] = position.Z;

	points_x[2] = position.X;
	points_y[2] = position.Y;
	points_z[2] = position.Z;

	points_x[3] = position.X + 0.05f*shape_scale;
	points_y[3] = position.Y + 0.25f*shape_scale;
	points_z[3] = position.Z;

	points_x[4] = position.X;
	points_y[4] = position.Y + 0.25f*shape_scale;
	points_z[4] = position.Z;

	points_x[5] = position.X;
	points_y[5] = position.Y + 0.25f*shape_scale;
	points_z[5] = position.Z;

	//


	for (int i = 0; i < sh->Length; i++){
		sh[i] = CustomVertex::PositionNormalColored(Vector3(points_x[i], points_y[i], points_z[i]), Vector3(points_x[i], points_y[i], points_z[i]), shape_color);
	}

	return sh;
}//end of CreateVerticalBeam()

array<CustomVertex::PositionNormalColored>^ Sign_on_screen::CreateHorizontalBeam(const Vector3& position){
	array<CustomVertex::PositionNormalColored>^ sh = gcnew array<CustomVertex::PositionNormalColored>(6);
	points_x = gcnew array<FLOAT>(6);
	points_y = gcnew array<FLOAT>(6);
	points_z = gcnew array<FLOAT>(6);

	points_x[0] = position.X;
	points_y[0] = position.Y + 0.05f*shape_scale;
	points_z[0] = position.Z;

	points_x[1] = position.X;
	points_y[1] = position.Y + 0.05f*shape_scale;
	points_z[1] = position.Z;

	points_x[2] = position.X;
	points_y[2] = position.Y;
	points_z[2] = position.Z;

	points_x[3] = position.X + 0.25f*shape_scale;
	points_y[3] = position.Y + 0.05f*shape_scale;
	points_z[3] = position.Z;

	points_x[4] = position.X + 0.25f*shape_scale;
	points_y[4] = position.Y;
	points_z[4] = position.Z;

	points_x[5] = position.X + 0.25f*shape_scale;
	points_y[5] = position.Y;
	points_z[5] = position.Z;

	for (int i = 0; i < sh->Length; i++){
		sh[i] = CustomVertex::PositionNormalColored(Vector3(points_x[i], points_y[i], points_z[i]), Vector3(points_x[i], points_y[i], points_z[i]), shape_color);
	}

	return sh;
}//end of CreateHorizontalBeam()

array<CustomVertex::PositionNormalColored>^ Sign_on_screen::CreateHalfOfVerticalBeam(const Vector3& position){
	array<CustomVertex::PositionNormalColored>^ sh = gcnew array<CustomVertex::PositionNormalColored>(6);
	points_x = gcnew array<FLOAT>(6);
	points_y = gcnew array<FLOAT>(6);
	points_z = gcnew array<FLOAT>(6);

	points_x[0] = position.X + 0.05f*shape_scale;
	points_y[0] = position.Y;
	points_z[0] = position.Z;

	points_x[1] = position.X + 0.05f*shape_scale;
	points_y[1] = position.Y;
	points_z[1] = position.Z;

	points_x[2] = position.X;
	points_y[2] = position.Y;
	points_z[2] = position.Z;

	points_x[3] = position.X + 0.05f*shape_scale;
	points_y[3] = position.Y + 0.125f*shape_scale;
	points_z[3] = position.Z;

	points_x[4] = position.X;
	points_y[4] = position.Y + 0.125f*shape_scale;
	points_z[4] = position.Z;

	points_x[5] = position.X;
	points_y[5] = position.Y + 0.125f*shape_scale;
	points_z[5] = position.Z;

	//


	for (int i = 0; i < sh->Length; i++){
		sh[i] = CustomVertex::PositionNormalColored(Vector3(points_x[i], points_y[i], points_z[i]), Vector3(points_x[i], points_y[i], points_z[i]), shape_color);
	}

	return sh;
}//end of CreateHalfOfVerticalBeam()

array<CustomVertex::PositionNormalColored>^ Sign_on_screen::CreateHalfOfHorizontalBeam(const Vector3& position){
	array<CustomVertex::PositionNormalColored>^ sh = gcnew array<CustomVertex::PositionNormalColored>(6);
	points_x = gcnew array<FLOAT>(6);
	points_y = gcnew array<FLOAT>(6);
	points_z = gcnew array<FLOAT>(6);

	points_x[0] = position.X;
	points_y[0] = position.Y + 0.05f*shape_scale;
	points_z[0] = position.Z;

	points_x[1] = position.X;
	points_y[1] = position.Y + 0.05f*shape_scale;
	points_z[1] = position.Z;

	points_x[2] = position.X;
	points_y[2] = position.Y;
	points_z[2] = position.Z;

	points_x[3] = position.X + 0.125f*shape_scale;
	points_y[3] = position.Y + 0.05f*shape_scale;
	points_z[3] = position.Z;

	points_x[4] = position.X + 0.125f*shape_scale;
	points_y[4] = position.Y;
	points_z[4] = position.Z;

	points_x[5] = position.X + 0.125f*shape_scale;
	points_y[5] = position.Y;
	points_z[5] = position.Z;

	for (int i = 0; i < sh->Length; i++){
		sh[i] = CustomVertex::PositionNormalColored(Vector3(points_x[i], points_y[i], points_z[i]), Vector3(points_x[i], points_y[i], points_z[i]), shape_color);
	}

	return sh;
}//end of CreateHalfOfHorizontalBeam()


array<CustomVertex::PositionNormalColored>^ Sign_on_screen::CreateSmallSquare(const Vector3& position){
	array<CustomVertex::PositionNormalColored>^ sh = gcnew array<CustomVertex::PositionNormalColored>(6);
	points_x = gcnew array<FLOAT>(6);
	points_y = gcnew array<FLOAT>(6);
	points_z = gcnew array<FLOAT>(6);

	points_x[0] = position.X;
	points_y[0] = position.Y + 0.05f*shape_scale;
	points_z[0] = position.Z;

	points_x[1] = position.X;
	points_y[1] = position.Y + 0.05f*shape_scale;
	points_z[1] = position.Z;

	points_x[2] = position.X;
	points_y[2] = position.Y;
	points_z[2] = position.Z;

	points_x[3] = position.X + 0.05f*shape_scale;
	points_y[3] = position.Y + 0.05f*shape_scale;
	points_z[3] = position.Z;

	points_x[4] = position.X + 0.05f*shape_scale;
	points_y[4] = position.Y;
	points_z[4] = position.Z;

	points_x[5] = position.X + 0.05f*shape_scale;
	points_y[5] = position.Y;
	points_z[5] = position.Z;

	for (int i = 0; i < sh->Length; i++){
		sh[i] = CustomVertex::PositionNormalColored(Vector3(points_x[i], points_y[i], points_z[i]), Vector3(points_x[i], points_y[i], points_z[i]), shape_color);
	}

	return sh;
}//end of CreateSmallSquare()