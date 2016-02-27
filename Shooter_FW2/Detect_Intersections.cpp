#include "Detect_Intersections.h"
#include <math.h>

Detect_Intersections::Detect_Intersections()
{
}


Detect_Intersections::~Detect_Intersections()
{
}

bool Detect_Intersections::CalculateForShoting(array<Vector3>^ shot_coord, array<Vector3>^ obj_coord){
	//dla pierwszego i ostatniego elementu tablic nale�y sprawdzi� "zachodzenie na siebie" przedzia��w wsp�rz�dnej Z
	if (obj_coord != nullptr){
		if (shot_coord[0].Z + shot_coord[1].Z >= obj_coord[0].Z){
			if (shot_coord[0].X + shot_coord[1].X < obj_coord[0].X + obj_coord[1].X && shot_coord[0].X - shot_coord[1].X > obj_coord[0].X - obj_coord[1].X)
				if (shot_coord[0].Y + shot_coord[1].Y < obj_coord[0].Y + obj_coord[1].Y && shot_coord[0].Y - shot_coord[1].Y > obj_coord[0].Y - obj_coord[1].Y)
					return true;
		}
	}

	return false;
}

bool Detect_Intersections::CalculatePlayerShipForShoting(array<Vector3>^ shot_coord, array<Vector3>^ obj_coord){
	//dla pierwszego i ostatniego elementu tablic nale�y sprawdzi� "zachodzenie na siebie" przedzia��w wsp�rz�dnej Z
	if (obj_coord != nullptr){
		if (shot_coord[0].Z + shot_coord[1].Z <= obj_coord[0].Z){
			if (shot_coord[0].X + shot_coord[1].X < obj_coord[0].X + obj_coord[1].X && shot_coord[0].X - shot_coord[1].X > obj_coord[0].X - obj_coord[1].X)
				if (shot_coord[0].Y + shot_coord[1].Y < obj_coord[0].Y + obj_coord[1].Y && shot_coord[0].Y - shot_coord[1].Y > obj_coord[0].Y)
					return true;
		}
	}

	return false;
}

bool Detect_Intersections::CalculateForHitingPlayerShip(array<Vector3>^ pl_ship_coord, array<Vector3>^ obj_coord){
	//dla pierwszego i ostatniego elementu tablic nale�y sprawdzi� "zachodzenie na siebie" przedzia��w wsp�rz�dnej Z
	float obj_nose_Z = obj_coord[0].Z + obj_coord[1].Z;
	float obj_nose_Y = obj_coord[0].Y + 0.143f*obj_coord[1].Y;
	float player_nose_Z = pl_ship_coord[0].Z + pl_ship_coord[1].Z - obj_nose_Z;
	float obj_scale = abs(obj_coord[1].Z) / 2.0f;
	float ship_hei = pl_ship_coord[0].Y + pl_ship_coord[1].Y;
	float obj_hei = obj_coord[0].Y + obj_coord[1].Y;

	if (obj_coord != nullptr){
		//nale�y najpierw wykry� zgodno�� po�o�enia "wg��b" ekranu oraz jej przedzia� - inny dla nosa, inny dla przodu i inny dla ty�u statku
		if (obj_nose_Z<=pl_ship_coord[0].Z + pl_ship_coord[1].Z && obj_nose_Z>pl_ship_coord[0].Z + 0.9f*pl_ship_coord[1].Z){ //w tym wypadku istnieje tylko mo�liwo�� "zderzenia si�" nosami, a 0.9 to cz�� d�ugo�ci od kt�rej wyst�puje nos statku
			if (abs(pl_ship_coord[0].X - obj_coord[0].X) <= 0.223f*pl_ship_coord[1].X || abs(pl_ship_coord[0].X - obj_coord[0].X) <= 0.223*obj_coord[1].X){ //0.223 to proporcja szeroko�ci nosa statku do szeroko�ci ca�ego statku
				//wykryta jest mo�liwo�� "zahaczenia" si� statk�w bokami - wsp�rz�dne poziome si� pokrywaj�
				if (ship_hei > obj_coord[0].Y && pl_ship_coord[0].Y < obj_hei){ //wykrycie mo�liwo�ci przeci�cia na pionowych wsp�rz�dnych
					//wykryta jest mo�liwo�� zderzenia ze wzgl�du na pionow� sk�adow� po�o�enia statk�w
					if ((obj_nose_Y < pl_ship_coord[0].Y + 0.286f*pl_ship_coord[1].Y && obj_coord[0].Y >= pl_ship_coord[0].Y) || (pl_ship_coord[0].Y + 0.143f*pl_ship_coord[1].Y <obj_coord[0].Y + 0.286f*obj_coord[1].Y && pl_ship_coord[0].Y + 0.143f*pl_ship_coord[1].Y >obj_coord[0].Y))
						return true;
					
				}
			}
		}
		else if (obj_nose_Z<=pl_ship_coord[0].Z + 0.9f*pl_ship_coord[1].Z && obj_nose_Z>=pl_ship_coord[0].Z + 0.375f*pl_ship_coord[1].Z){ // 0.375 to warto�� proporcji statku wzd�u� d�ugo�ci z, na kt�rej y=86%*y_max, do ca�ego wymiaru statku
			float f1 = ((-0.318f)*(abs(obj_coord[1].Z) - (0.9f*pl_ship_coord[1].Z - obj_nose_Z)) + obj_scale*0.673f);
			if (obj_coord[0].X - f1 <= pl_ship_coord[0].X + 0.223f*pl_ship_coord[1].X && obj_coord[0].X +f1 >= pl_ship_coord[0].X - 0.223f*pl_ship_coord[1].X){
				if (ship_hei > obj_coord[0].Y && pl_ship_coord[0].Y < obj_hei){ //wykrycie mo�liwo�ci przeci�cia na pionowych wsp�rz�dnych
					if (obj_coord[0].Y >= pl_ship_coord[0].Y && obj_coord[0].Y <= (pl_ship_coord[0].Y) + (-0.190f*obj_nose_Z + obj_scale*0.443f))
						return true;
					else if (pl_ship_coord[0].Y >= obj_coord[0].Y && pl_ship_coord[0].Y <= obj_coord[0].Y + (-0.190f*(abs(obj_coord[1].Z) - player_nose_Z) + obj_scale*0.443f))
						return true;
				}
			}
		}
		else if (obj_nose_Z<pl_ship_coord[0].Z + 0.375f*pl_ship_coord[1].Z && obj_nose_Z>pl_ship_coord[0].Z+0.15f*pl_ship_coord[1].Z){ // 0.15 to warto�� proporcji statku wzd�u� d�ugo�ci z, na kt�rej y=y_max, do ca�ego wymiaru statku
			float z = abs(obj_coord[1].Z) - (0.35f*pl_ship_coord[1].Z - obj_nose_Z);
			float f2;
			if (z>0.35*abs(obj_coord[1].Z))
				f2=-0.31f*z + obj_scale*0.673f;
			else 
				f2 = (0.286f*(z)+obj_scale*0.25f);

			if (obj_coord[0].X - f2 <= pl_ship_coord[0].X + pl_ship_coord[1].X && obj_coord[0].X + f2 >= pl_ship_coord[0].X - pl_ship_coord[1].X){
				//wykryta jest mo�liwo�� "zahaczenia" si� statk�w bokami - wsp�rz�dne poziome si� pokrywaj�
				if (ship_hei > obj_coord[0].Y && pl_ship_coord[0].Y < obj_hei){ //wykrycie mo�liwo�ci przeci�cia na pionowych wsp�rz�dnych
					if (obj_coord[0].Y >= pl_ship_coord[0].Y && obj_nose_Y < pl_ship_coord[0].Y + (-0.143*obj_nose_Z + obj_scale*0.393))
						return true;
					else if (pl_ship_coord[0].Y >= obj_coord[0].Y && pl_ship_coord[0].Y <= obj_coord[0].Y + (-0.143*(abs(obj_coord[1].Z) - player_nose_Z) + obj_scale*0.393))
						return true;
				}
			}
		}
		else if (obj_nose_Z<pl_ship_coord[0].Z + 0.15f*pl_ship_coord[1].Z ){
			float z = abs(obj_coord[1].Z) - (0.35f*pl_ship_coord[1].Z - obj_nose_Z);
			float f3;
			if (z>0.35*abs(obj_coord[1].Z))
				f3 = -0.31f*z + obj_scale*0.673f;
			else
				f3 = (0.286f*(z)+obj_scale*0.25f);

			if (obj_coord[0].X - f3 <= pl_ship_coord[0].X + pl_ship_coord[1].X && obj_coord[0].X + f3 >= pl_ship_coord[0].X - pl_ship_coord[1].X){
				if (ship_hei > obj_coord[0].Y && pl_ship_coord[0].Y < obj_hei){ //wykrycie mo�liwo�ci przeci�cia na pionowych wsp�rz�dnych
					if (obj_coord[0].Y >= pl_ship_coord[0].Y && obj_nose_Y < pl_ship_coord[0].Y + (0.8333f*obj_nose_Z + obj_scale*0.1f))
						return true;
					else if (pl_ship_coord[0].Y >= obj_coord[0].Y && pl_ship_coord[0].Y <= obj_coord[0].Y + (0.8333f*(abs(obj_coord[1].Z) - player_nose_Z) + obj_scale*0.1f))
						return true;
				}
			}
		}
	}

	return false;
}
