#include "Shot.h"


Shot::Shot()
{
	if (points_assigned == 0)
		Assign_Coordinates();

	shape_position = Vector3(0, 0, 0);
	intersect_pts = gcnew array < Vector3 >(8);
	shape_ptr = CreateShape();
	SetIntersectionPoints(intersect_pts); //dodaj punkty kluczowe dla przeciêæ
}

Shot::Shot(const Vector3 position){
	if (points_assigned == 0)
		Assign_Coordinates();
	
	shape_position = position;
	shape_position.Z -= 0.25f;
	intersect_pts = gcnew array < Vector3 >(8);
	shape_color = System::Drawing::Color::Gold.ToArgb();
	shape_ptr = CreateShape();
	SetIntersectionPoints(intersect_pts);
}

Shot::Shot(const Vector3 position, const int& color){
	if (points_assigned == 0)
		Assign_Coordinates();
	shape_color = color;
	shape_position = position;
	shape_position.Z -= 0.25f;
	intersect_pts = gcnew array < Vector3 >(8);
	shape_ptr = CreateShape();
	SetIntersectionPoints(intersect_pts);
}

Shot::~Shot()
{
}

array<CustomVertex::PositionNormalColored>^ Shot::CreateShape(){
	
	array<CustomVertex::PositionNormalColored>^ cylinder = gcnew array<CustomVertex::PositionNormalColored>(731);

	
	int cyl_count = 0;
	for (int i = 0; i < znacznik_konca; i++){
		cylinder[i++] = CustomVertex::PositionNormalColored(Vector3(v1[0].X + shape_position.X, v1[0].Y + shape_position.Y, v1[0].Z + shape_position.Z), Vector3(v1[0].X + shape_position.X, v1[0].Y + shape_position.Y, v1[0].Z + shape_position.Z), shape_color);
		cylinder[i] = CustomVertex::PositionNormalColored(Vector3(v1[i].X + shape_position.X, v1[i].Y + shape_position.Y, v1[i].Z + shape_position.Z), Vector3(v1[i].X + shape_position.X, v1[i].Y + shape_position.Y, v1[i].Z + shape_position.Z), shape_color);
		cyl_count = i;
	}
	//zakoñczone sk³adanie dolnej podstawy


	int ii = cyl_count;
	while (ii <drugi_znacznik){
		cylinder[ii++] = CustomVertex::PositionNormalColored(Vector3(v1[ii].X + shape_position.X, v1[ii].Y + shape_position.Y, v1[ii].Z + shape_position.Z), Vector3(v1[ii].X + shape_position.X, v1[ii].Y + shape_position.Y, v1[ii].Z + shape_position.Z), shape_color);
		cylinder[ii++] = CustomVertex::PositionNormalColored(Vector3(v1[ii].X + shape_position.X, v1[ii].Y + shape_position.Y, v1[ii].Z + shape_position.Z), Vector3(v1[ii].X + shape_position.X, v1[ii].Y + shape_position.Y, v1[ii].Z + shape_position.Z), shape_color);
	}
	//zakoñczono sk³adanie powierzchnii walcowej
	Vector3 v = Vector3(v2.X + shape_position.X, v2.Y + shape_position.Y, v2.Z + shape_position.Z);
	for (int i = drugi_znacznik+1; i < cylinder->Length; i++){
		cylinder[i++] = CustomVertex::PositionNormalColored(v, v, shape_color);
		cylinder[i] = CustomVertex::PositionNormalColored(Vector3(v1[i].X + shape_position.X, v1[i].Y + shape_position.Y, v1[i].Z + shape_position.Z), Vector3(v1[i].X + shape_position.X, v1[i].Y + shape_position.Y, v1[i].Z + shape_position.Z), shape_color);
	}
	//zakoñczone sk³adanie dolnej podstawy
	//intersect_pts[0] = Vector3(shape_position.X, shape_position.Y + shape_scale, shape_position.Z + cyl_height);
	//intersect_pts[1] = Vector3(shape_position.X + shape_scale, shape_position.Y, shape_position.Z + cyl_height);
	//intersect_pts[2] = Vector3(shape_position.X, shape_position.Y - shape_scale, shape_position.Z + cyl_height);
	//intersect_pts[3] = Vector3(shape_position.X - shape_scale, shape_position.Y, shape_position.Z + cyl_height);
	//
	//intersect_pts[4] = Vector3(shape_position.X, shape_position.Y + shape_scale, shape_position.Z - cyl_height);
	//intersect_pts[5] = Vector3(shape_position.X + shape_scale, shape_position.Y, shape_position.Z - cyl_height);
	//intersect_pts[6] = Vector3(shape_position.X, shape_position.Y - shape_scale, shape_position.Z - cyl_height);
	//intersect_pts[7] = Vector3(shape_position.X - shape_scale, shape_position.Y, shape_position.Z - cyl_height);

	intersect_pts[0] = Vector3(shape_position.X, shape_position.Y, shape_position.Z);
	intersect_pts[1] = Vector3(shape_scale, shape_scale, cyl_height);

	return cylinder;
}


void Shot::Assign_Coordinates(){

	float add = -shape_scale*1.0f;

	int counter = 0;
	for (double angle = 0; angle <= 2 * M_PI + M_PI_2 / 45; angle += M_PI_2 / 45){ //czyli co 2 stopnie kolejny bok trójk¹ta
		points_x[counter] = add*cosf((float)angle);
		points_y[counter] = -0.5f*cyl_height*sinf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*sinf(rot_x);
		points_z[counter] = -0.5f*cyl_height*cosf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*cosf(rot_x);
		v1[counter] = v1[counter++] = Vector3(points_x[counter], points_y[counter], points_z[counter]);
	}
	//zakoñczone sk³adanie punktów z dolnej podstawy
	znacznik_konca = counter;

	for (double angle = 0; angle <= 2 * M_PI + M_PI_2 / 45; angle += M_PI_2 / 45){ //czyli co 2 stopnie kolejny bok trójk¹ta
		points_x[counter] = add*cosf((float)angle);
		points_y[counter] = 0.5f*cyl_height*sinf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*sinf(rot_x);
		points_z[counter] = 0.5f*cyl_height*cosf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*cosf(rot_x);
		v1[counter++] = Vector3(points_x[counter], points_y[counter], points_z[counter]);
		//punkt z gory
		points_x[counter] = add*cosf((float)angle);
		points_y[counter] = -0.5f*cyl_height*sinf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*sinf(rot_x);
		points_z[counter] = -0.5f*cyl_height*cosf(rot_x + (float)M_PI_2) + add*sinf((float)angle)*cosf(rot_x);
		v1[counter++] = Vector3(points_x[counter], points_y[counter], points_z[counter]);
		//punkt z dolu
	}
	drugi_znacznik = counter;

	int ii = 0;
	while (ii<znacznik_konca){
		v1[counter++] = Vector3(points_x[ii], points_y[ii] + cyl_height*sinf(rot_x + (float)M_PI_2), points_z[ii] + cyl_height*cosf(rot_x + (float)M_PI_2));
		ii++;
	}
	
	Vector3 v2 = Vector3(points_x[0], points_y[0] + sinf(rot_x + (float)M_PI_2)*cyl_height, points_z[0] + cosf(rot_x + (float)M_PI_2)*cyl_height);

	points_assigned = 1;
}