#include "Pojemnik_na_bryly.h"


Pojemnik_na_bryly::Pojemnik_na_bryly()
{
	licznik_bryl = 0;
	pojemnik_z_brylami = nullptr;
}


Pojemnik_na_bryly::~Pojemnik_na_bryly()
{
}

void Pojemnik_na_bryly::Add_component(FLOAT R,Vector3 pos, INT col){
	licznik_bryl += 1;
	tab_obiektow.Add(gcnew Kula(R,pos,col));
}

void Pojemnik_na_bryly::Add_component(Kula^ k){
	licznik_bryl += 1;
	tab_obiektow.Add(k);
}

void Pojemnik_na_bryly::Add_component(Bryla_3D_bez_punktow^ bryla){
	licznik_bryl += 1;
	tab_obiektow.Add(bryla);
}

void Pojemnik_na_bryly::Add_component(Enemy_Ships^ ship){
	licznik_bryl += 1;
	tab_obiektow.Add(ship);
}

void Pojemnik_na_bryly::Delete_component(const int& jj){
	if (Get_licznik_bryl()-1 >= jj){
		tab_obiektow.RemoveAt(jj);
		licznik_bryl--;
	}
}

//Kula ^ Pojemnik_na_bryly::Get_current_pointer(){
//	if (pojemnik_z_brylami == nullptr){
//		pojemnik_z_brylami = dynamic_cast<Kula ^>(tab_obiektow[0]);
//	}
//	return pojemnik_z_brylami;
//}

INT Pojemnik_na_bryly::Get_licznik_bryl(){
	return licznik_bryl;
}

//Kula ^ Pojemnik_na_bryly::Set_current_pointer(int jj){
	//pojemnik_z_brylami = dynamic_cast<Kula ^>(tab_obiektow[jj]);
	//return pojemnik_z_brylami;
//}

Bryla_3D_bez_punktow^ Pojemnik_na_bryly::Set_current_pointer(int jj){
	return dynamic_cast<Bryla_3D_bez_punktow^>(tab_obiektow[jj]);
}

void Pojemnik_na_bryly::Modify_Object_Color(const int& j, const int& kol){
	Set_current_pointer(j);
	pojemnik_z_brylami->ChangeObjectColor(kol);
	tab_obiektow.Insert(j,pojemnik_z_brylami);	
	tab_obiektow.RemoveAt(j + 1);
}

void Pojemnik_na_bryly::Move_Object(const int& j, const Vector3& translation_vector){
	Set_current_pointer(j);
	pojemnik_z_brylami->Move_Kula(translation_vector);
	tab_obiektow.Insert(j, pojemnik_z_brylami);
	tab_obiektow.RemoveAt(j + 1);
}

void Pojemnik_na_bryly::RemoveAllComponents(){
	for (int i = licznik_bryl-1; i >= 0; i--)
		Delete_component(i);
	licznik_bryl = 0;
}