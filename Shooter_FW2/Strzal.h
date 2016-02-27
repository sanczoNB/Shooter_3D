#pragma once
#include "Walec.h"

public ref class Strzal
	: public Walec{
public:
	Strzal();
	Strzal(const Vector3& position);
	~Strzal();

	//virtual array<CustomVertex::PositionNormalColored>^ Strzal::CreateShape() override;
};

