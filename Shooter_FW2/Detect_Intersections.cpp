#include "Detect_Intersections.h"
#include <math.h>

Detect_Intersections::Detect_Intersections()
{
}


Detect_Intersections::~Detect_Intersections()
{
}

bool Detect_Intersections::CalculateForShoting(array<Vector3>^ shot_coord, array<Vector3>^ obj_coord){
	//dla pierwszego i ostatniego elementu tablic nale¿y sprawdziæ "zachodzenie na siebie" przedzia³ów wspó³rzêdnej Z
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
	//dla pierwszego i ostatniego elementu tablic nale¿y sprawdziæ "zachodzenie na siebie" przedzia³ów wspó³rzêdnej Z
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
	//dla pierwszego i ostatniego elementu tablic nale¿y sprawdziæ "zachodzenie na siebie" przedzia³ów wspó³rzêdnej Z
	float obj_nose_Z = obj_coord[0].Z + obj_coord[1].Z;
	float obj_nose_Y = obj_coord[0].Y + 0.143f*obj_coord[1].Y;
	float player_nose_Z = pl_ship_coord[0].Z + pl_ship_coord[1].Z - obj_nose_Z;
	float obj_scale = abs(obj_coord[1].Z) / 2.0f;
	float ship_hei = pl_ship_coord[0].Y + pl_ship_coord[1].Y;
	float obj_hei = obj_coord[0].Y + obj_coord[1].Y;

	if (obj_coord != nullptr){
		//nale¿y najpierw wykryæ zgodnoœæ po³o¿enia "wg³¹b" ekranu oraz jej przedzia³ - inny dla nosa, inny dla przodu i inny dla ty³u statku
		if (obj_nose_Z<=pl_ship_coord[0].Z + pl_ship_coord[1].Z && obj_nose_Z>pl_ship_coord[0].Z + 0.9f*pl_ship_coord[1].Z){ //w tym wypadku istnieje tylko mo¿liwoœæ "zderzenia siê" nosami, a 0.9 to czêœæ d³ugoœci od której wystêpuje nos statku
			if (abs(pl_ship_coord[0].X - obj_coord[0].X) <= 0.223f*pl_ship_coord[1].X || abs(pl_ship_coord[0].X - obj_coord[0].X) <= 0.223*obj_coord[1].X){ //0.223 to proporcja szerokoœci nosa statku do szerokoœci ca³ego statku
				//wykryta jest mo¿liwoœæ "zahaczenia" siê statków bokami - wspó³rzêdne poziome siê pokrywaj¹
				if (ship_hei > obj_coord[0].Y && pl_ship_coord[0].Y < obj_hei){ //wykrycie mo¿liwoœci przeciêcia na pionowych wspó³rzêdnych
					//wykryta jest mo¿liwoœæ zderzenia ze wzglêdu na pionow¹ sk³adow¹ po³o¿enia statków
					if ((obj_nose_Y < pl_ship_coord[0].Y + 0.286f*pl_ship_coord[1].Y && obj_coord[0].Y >= pl_ship_coord[0].Y) || (pl_ship_coord[0].Y + 0.143f*pl_ship_coord[1].Y <obj_coord[0].Y + 0.286f*obj_coord[1].Y && pl_ship_coord[0].Y + 0.143f*pl_ship_coord[1].Y >obj_coord[0].Y))
						return true;
					
				}
			}
		}
		else if (obj_nose_Z<=pl_ship_coord[0].Z + 0.9f*pl_ship_coord[1].Z && obj_nose_Z>=pl_ship_coord[0].Z + 0.375f*pl_ship_coord[1].Z){ // 0.375 to wartoœæ proporcji statku wzd³u¿ d³ugoœci z, na której y=86%*y_max, do ca³ego wymiaru statku
			float f1 = ((-0.318f)*(abs(obj_coord[1].Z) - (0.9f*pl_ship_coord[1].Z - obj_nose_Z)) + obj_scale*0.673f);
			if (obj_coord[0].X - f1 <= pl_ship_coord[0].X + 0.223f*pl_ship_coord[1].X && obj_coord[0].X +f1 >= pl_ship_coord[0].X - 0.223f*pl_ship_coord[1].X){
				if (ship_hei > obj_coord[0].Y && pl_ship_coord[0].Y < obj_hei){ //wykrycie mo¿liwoœci przeciêcia na pionowych wspó³rzêdnych
					if (obj_coord[0].Y >= pl_ship_coord[0].Y && obj_coord[0].Y <= (pl_ship_coord[0].Y) + (-0.190f*obj_nose_Z + obj_scale*0.443f))
						return true;
					else if (pl_ship_coord[0].Y >= obj_coord[0].Y && pl_ship_coord[0].Y <= obj_coord[0].Y + (-0.190f*(abs(obj_coord[1].Z) - player_nose_Z) + obj_scale*0.443f))
						return true;
				}
			}
		}
		else if (obj_nose_Z<pl_ship_coord[0].Z + 0.375f*pl_ship_coord[1].Z && obj_nose_Z>pl_ship_coord[0].Z+0.15f*pl_ship_coord[1].Z){ // 0.15 to wartoœæ proporcji statku wzd³u¿ d³ugoœci z, na której y=y_max, do ca³ego wymiaru statku
			float z = abs(obj_coord[1].Z) - (0.35f*pl_ship_coord[1].Z - obj_nose_Z);
			float f2;
			if (z>0.35*abs(obj_coord[1].Z))
				f2=-0.31f*z + obj_scale*0.673f;
			else 
				f2 = (0.286f*(z)+obj_scale*0.25f);

			if (obj_coord[0].X - f2 <= pl_ship_coord[0].X + pl_ship_coord[1].X && obj_coord[0].X + f2 >= pl_ship_coord[0].X - pl_ship_coord[1].X){
				//wykryta jest mo¿liwoœæ "zahaczenia" siê statków bokami - wspó³rzêdne poziome siê pokrywaj¹
				if (ship_hei > obj_coord[0].Y && pl_ship_coord[0].Y < obj_hei){ //wykrycie mo¿liwoœci przeciêcia na pionowych wspó³rzêdnych
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
				if (ship_hei > obj_coord[0].Y && pl_ship_coord[0].Y < obj_hei){ //wykrycie mo¿liwoœci przeciêcia na pionowych wspó³rzêdnych
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
