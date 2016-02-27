#include "Sign_on_screen.h"

#pragma once
public ref class Letters_on_screen
	: public  Sign_on_screen{
private:
	char letter;
public:
	Letters_on_screen();
	Letters_on_screen(const char& let, const Vector3& pos, const float& scale, const int& color); //0.1 to podstawowa grubosc linii tworz¹cych cyfrê, a 0.7 to jej wysokosc
	Letters_on_screen(String^ str, const Vector3& pos, const float& scale, const int& color);
	~Letters_on_screen();

	virtual array<CustomVertex::PositionNormalColored>^ CreateShape() override;
	virtual array<CustomVertex::PositionNormalColored>^ ChangeObjectColor(const int& kol) override;

private:
	array<CustomVertex::PositionNormalColored>^ CreateA();
	//array<CustomVertex::PositionNormalColored>^ CreateB();
	array<CustomVertex::PositionNormalColored>^ CreateC();
	array<CustomVertex::PositionNormalColored>^ CreateD();
	array<CustomVertex::PositionNormalColored>^ CreateE();
	array<CustomVertex::PositionNormalColored>^ CreateF();
	array<CustomVertex::PositionNormalColored>^ CreateG();
	array<CustomVertex::PositionNormalColored>^ CreateH();
	array<CustomVertex::PositionNormalColored>^ CreateI();	
	//array<CustomVertex::PositionNormalColored>^ CreateJ();
	//array<CustomVertex::PositionNormalColored>^ CreateK();
	array<CustomVertex::PositionNormalColored>^ CreateL();
	array<CustomVertex::PositionNormalColored>^ CreateM();
	array<CustomVertex::PositionNormalColored>^ CreateN();
	array<CustomVertex::PositionNormalColored>^ CreateO();
	array<CustomVertex::PositionNormalColored>^ CreateP();
	//array<CustomVertex::PositionNormalColored>^ CreateQ();
	array<CustomVertex::PositionNormalColored>^ CreateR();
	//array<CustomVertex::PositionNormalColored>^ CreateS();
	array<CustomVertex::PositionNormalColored>^ CreateT();
	array<CustomVertex::PositionNormalColored>^ CreateU();
	array<CustomVertex::PositionNormalColored>^ CreateV();
	array<CustomVertex::PositionNormalColored>^ CreateW();
	//array<CustomVertex::PositionNormalColored>^ CreateX();
	array<CustomVertex::PositionNormalColored>^ CreateY();
	//array<CustomVertex::PositionNormalColored>^ CreateZ();
};

