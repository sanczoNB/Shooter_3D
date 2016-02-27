#pragma once
#include "Player_Ship.h"

public ref class Enemy_Ships
 : public Player_Ship{
public:
	Enemy_Ships(const Vector3& pos);
	~Enemy_Ships();

	//virtual array<CustomVertex::PositionNormalColored>^ create_ship() override;
	void RandomShipMove(const int& direction);
};

