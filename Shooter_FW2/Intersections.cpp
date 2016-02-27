#include "Intersections.h"


Intersections::Intersections()
{
}


Intersections::~Intersections()
{
}

void Intersections::SetIntersectionPoints(array<Vector3>^ pointer){
	intersection_points = pointer;
}

array<Vector3>^ Intersections::GetIntersectionPoints(){
	return intersection_points;
}
