#include "Letters_on_screen.h"


Letters_on_screen::Letters_on_screen(){
	shape_position = Vector3(0.0f, 0.0f, 0.0f);
	shape_color = System::Drawing::Color::Red.ToArgb();
	shape_scale = 1.0f;
	letter = 'A';
	shape_ptr = CreateShape();
}

Letters_on_screen::Letters_on_screen(const char& let, const Vector3& pos, const float& scale, const int& color){
	shape_position = pos;
	shape_color = color;
	shape_scale = scale;
	letter = let;
	shape_ptr = CreateShape();
}

Letters_on_screen::Letters_on_screen(String^ str, const Vector3& pos, const float& scale, const int& color){
	shape_position = pos;
	shape_color = color;
	shape_scale = scale;
	shape_ptr = gcnew array<CustomVertex::PositionNormalColored>(300*6);
	array<CustomVertex::PositionNormalColored>^ part_of_str;
	int shape_ptr_couter = 0;
	for (int i = 0; i < str->Length; i++){
		letter = str[i];
		if (letter != ' '){
			part_of_str = CreateShape();
			for (int j = 0; j < part_of_str->Length; j++)
				shape_ptr[shape_ptr_couter++] = part_of_str[j];
		}
		shape_position.X += 0.45f*shape_scale;
	}
	
}


Letters_on_screen::~Letters_on_screen(){
}

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateShape(){
	array<CustomVertex::PositionNormalColored>^ shape;

	switch (letter){
	case 'a':
	case 'A': shape = CreateA(); break;
	//case 'b':
	//case 'B': shape = CreateOne(); break;
	case 'c':
	case 'C': shape = CreateC(); break;
	case 'd': 
	case 'D': shape = CreateD(); break;
	case 'e':
	case 'E': shape = CreateE(); break;
	case 'f':
	case 'F': shape = CreateF(); break;
	case 'g':
	case 'G': shape = CreateG(); break;
	case 'h': 
	case 'H': shape = CreateH();  break;
	case 'i':
	case 'I': shape = CreateI(); break;
	//case 'j': 
	//case 'J': shape = CreateJ(); break;
	//case 'k':
	//case 'K': shape = CreateK(); break;
	case 'l':
	case 'L': shape = CreateL(); break;
	case 'm':
	case 'M': shape = CreateM(); break;
	case 'n':
	case 'N': shape = CreateN(); break;
	case 'o':
	case 'O': shape = CreateO(); break;
	case 'p':
	case 'P': shape = CreateP(); break;
	//case 'q':
	//case 'Q': shape = CreateQ(); break;
	case 'r':
	case 'R': shape = CreateR(); break;
	//case 's':
	//case 'S': shape = CreateS(); break;
	case 't':
	case 'T': shape = CreateT(); break;
	case 'u':
	case 'U': shape = CreateU(); break;
	case 'v':
	case 'V': shape = CreateV(); break;
	case 'w':
	case 'W': shape = CreateW(); break;
	//case 'x':
	//case 'X': shape = CreateX(); break;
	case 'y': 
	case 'Y': shape = CreateY(); break;
	//case 'z':
	//case 'Z': shape = CreateZ(); break;
	}

	return shape;
}


array<CustomVertex::PositionNormalColored>^ Letters_on_screen::ChangeObjectColor(const int& kol){
	array<CustomVertex::PositionNormalColored>^ shape = gcnew array < CustomVertex::PositionNormalColored >(10);

	return shape;
}

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateA(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(6 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);
	
	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.25f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateA()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateC(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(4 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateC()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateD(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(6 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	v.Y -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.15f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateD()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateE(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(5 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateE()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateF(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(4 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateHalfOfHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateF()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateG(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(6 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	v.X -= 0.125f*shape_scale;
	shp_beam = CreateHalfOfHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.125f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateG()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateH(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(5 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateH()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateI(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(2 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	v.X += 0.125f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateI()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateL(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(3 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateL()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateM(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(7 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	v.X += 0.125f*shape_scale;
	v.Y += 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.125f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	v.X -= 0.075f*shape_scale;
	shp_beam = CreateHalfOfHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.175f*shape_scale;
	shp_beam = CreateHalfOfHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateM()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateN(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(9 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.05f*shape_scale;
	v.Y += 0.05f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.05f*shape_scale;
	v.Y += 0.05f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.025f*shape_scale;
	v.Y += 0.05f*shape_scale;
	shp_beam = CreateHalfOfVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.025f*shape_scale;
	v.Y += 0.125f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.05f*shape_scale;
	v.Y += 0.05f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateN()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateO(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(8 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	v.X += 0.05f*shape_scale;
	shp_beam = CreateHalfOfHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.45f*shape_scale;
	shp_beam = CreateHalfOfHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.075f*shape_scale;
	shp_beam = CreateHalfOfHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.45f*shape_scale;
	shp_beam = CreateHalfOfHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.125f*shape_scale;
	v.Y += 0.05f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.15f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateO()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateP(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(5 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.25f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateP()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateR(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(8 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.25f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.25f*shape_scale;
	v.X += 0.15f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.125f*shape_scale;
	v.X += 0.05f*shape_scale;
	shp_beam = CreateHalfOfVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.05f*shape_scale;
	v.X += 0.05f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateR()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateT(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(3 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	v.X += 0.125f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	v.X -= 0.125f*shape_scale;
	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateT()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateU(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(5 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	shp_beam = CreateHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateU()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateV(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(9 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	v.Y += 0.25f*shape_scale;
	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.05f*shape_scale;
	v.Y -= 0.05f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.05f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.025f*shape_scale;
	v.Y -= 0.125f*shape_scale;
	shp_beam = CreateHalfOfVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.025f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.025f*shape_scale;
	shp_beam = CreateHalfOfVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.025f*shape_scale;
	v.Y += 0.125f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.05f*shape_scale;
	shp_beam = CreateSmallSquare(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.05f*shape_scale;
	v.Y += 0.05f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);
	return shp;
}//end of CreateV()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateW(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(7 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	v.X += 0.125f*shape_scale;
	v.Y += 0.05f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.125f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.25f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.2f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y -= 0.05f*shape_scale;
	v.X -= 0.075f*shape_scale;
	shp_beam = CreateHalfOfHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.175f*shape_scale;
	shp_beam = CreateHalfOfHorizontalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	return shp;
}//end of CreateW()

array<CustomVertex::PositionNormalColored>^ Letters_on_screen::CreateY(){
	array<CustomVertex::PositionNormalColored>^ shp = gcnew array<CustomVertex::PositionNormalColored>(8 * 6);
	array<CustomVertex::PositionNormalColored>^ shp_beam = gcnew array<CustomVertex::PositionNormalColored>(6);
	Vector3 v = shape_position;
	int insert = 0;

	v.X += 0.125f*shape_scale;
	shp_beam = CreateVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.Y += 0.25f*shape_scale;
	for (int i = 0; i < 2; i++){
		v.X += 0.05f*shape_scale;
		v.Y += 0.05f*shape_scale;
		shp_beam = CreateSmallSquare(v);
		CopyBeamElements(shp_beam, shp, insert++);
	}

	v.X += 0.025f*shape_scale;
	shp_beam = CreateHalfOfVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X -= 0.25f*shape_scale;
	shp_beam = CreateHalfOfVerticalBeam(v);
	CopyBeamElements(shp_beam, shp, insert++);

	v.X += 0.025f*shape_scale;
	for (int i = 0; i < 3; i++){
		shp_beam = CreateSmallSquare(v);
		CopyBeamElements(shp_beam, shp, insert++);
		v.X += 0.05f*shape_scale;
		v.Y -= 0.05f*shape_scale;
	}

	return shp;
}//end of CreateY()