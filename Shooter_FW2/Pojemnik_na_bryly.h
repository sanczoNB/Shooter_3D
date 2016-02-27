#include "Kula.h"
#include "Bryla_3D_bez_punktow.h"
#include "Enemy_Ships.h"

using namespace System;
using namespace System::Collections;

#pragma once
public ref class Pojemnik_na_bryly
{
private:
	ArrayList tab_obiektow;
	Kula ^ pojemnik_z_brylami;
	INT licznik_bryl;
public:
	Pojemnik_na_bryly();
	~Pojemnik_na_bryly();
	void Add_component(FLOAT R, Vector3 pos, INT col);
	void Add_component(Bryla_3D_bez_punktow^ bryla);
	void Add_component(Enemy_Ships^ ship);
	void Add_component(Kula^ k);
	void Delete_component(const int& jj);
	//Bryla_3D^ GetCurrentPointer();
	//Kula ^ Get_current_pointer();
	INT Get_licznik_bryl();
	//Kula ^ Set_current_pointer(int jj);
	Bryla_3D_bez_punktow^ Set_current_pointer(int jj);

	void Modify_Object_Color(const int& j, const int& kol);
	void Move_Object(const int& j, const Vector3& translation_vector);
	void RemoveAllComponents();
};

