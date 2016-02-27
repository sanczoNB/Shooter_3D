#include "Sign_on_screen.h"

#pragma once
public ref class Digits_on_screen
	: Sign_on_screen{
private:
	int dgt;
public:
	Digits_on_screen();
	Digits_on_screen(const int& digit, const Vector3& pos, const float& scale, const int& color); //0.1 to podstawowa grubosc linii tworz¹cych cyfrê, a 0.7 to jej wysokosc
	~Digits_on_screen();



	virtual array<CustomVertex::PositionNormalColored>^ CreateShape() override;
	virtual array<CustomVertex::PositionNormalColored>^ ChangeObjectColor(const int& kol) override;
private:
	array<CustomVertex::PositionNormalColored>^ CreateOne();
	array<CustomVertex::PositionNormalColored>^ CreateTwo();
	array<CustomVertex::PositionNormalColored>^ CreateThree();
	array<CustomVertex::PositionNormalColored>^ CreateFour();
	array<CustomVertex::PositionNormalColored>^ CreateFive();
	array<CustomVertex::PositionNormalColored>^ CreateSix();
	array<CustomVertex::PositionNormalColored>^ CreateSeven();
	array<CustomVertex::PositionNormalColored>^ CreateEight();
	array<CustomVertex::PositionNormalColored>^ CreateNine();
	array<CustomVertex::PositionNormalColored>^ CreateZero();
};

