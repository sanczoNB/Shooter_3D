#include "Digits_on_screen.h"


Digits_on_screen::Digits_on_screen(){
	dgt = 0;
	shape_position = Vector3(0.0f, 0.0f, 0.0f);
	shape_color = System::Drawing::Color::Red.ToArgb();
	shape_scale = 1.0f;
	shape_ptr = CreateShape();
}

Digits_on_screen::Digits_on_screen(const int& digit, const Vector3& pos, const float& scale, const int& color){
	shape_position = pos;
	shape_color = color;
	dgt = digit;
	shape_scale = scale;
	shape_ptr = CreateShape();
}


Digits_on_screen::~Digits_on_screen()
{
}


array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateShape(){
	array<CustomVertex::PositionNormalColored>^ shape;
	//int rest[3] = { 0, 0, 0 };
	//if (dgt > 9){

	//}

	switch (dgt){
		case 0: shape = CreateZero(); break;
		case 1: shape = CreateOne(); break;
		case 2: shape = CreateTwo(); break;
		case 3: shape = CreateThree(); break;
		case 4: shape = CreateFour(); break;
		case 5: shape = CreateFive(); break;
		case 6: shape = CreateSix(); break;
		case 7: shape = CreateSeven();  break;
		case 8: shape = CreateEight(); break;
		case 9: shape = CreateNine(); break;
	}
	
	return shape;
}


array<CustomVertex::PositionNormalColored>^ Digits_on_screen::ChangeObjectColor(const int& kol){
	array<CustomVertex::PositionNormalColored>^ shape = gcnew array < CustomVertex::PositionNormalColored >(10);

	return shape;
}

array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateOne(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(2 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateOne()


array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateTwo(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(5 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	v.Y -= 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}


array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateThree(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(5*6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);
	
	v.Y += 0.25f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	v.Y -= 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateThree()

array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateFour(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(4 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);
	
	
	v.Y -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateFour()

array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateFive(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(5 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.X += 0.2f*shape_scale;
	v.Y -= 0.4f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateFive()

array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateSix(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(6 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y += 0.25f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.X += 0.2f*shape_scale;
	v.Y -= 0.45f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateSix()


array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateSeven(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(3 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	v.Y += 0.45f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	v.Y -= 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}// end of CreateSeven()


array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateEight(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(7 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y += 0.25f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);
	
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.X += 0.25f*shape_scale;
	v.Y -= 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateEight()

array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateNine(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(6 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y += 0.25f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.X += 0.25f*shape_scale;
	v.Y -= 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateNine()

array<CustomVertex::PositionNormalColored>^ Digits_on_screen::CreateZero(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(6 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.X += 0.25f*shape_scale;
	v.Y -= 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);


	v.Y -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateZero()
