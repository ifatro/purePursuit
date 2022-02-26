#pragma once
#include <math.h>
#include "Coord.h"
class Rotations
{

public:


	Coord calcPathCoordGlobalToCar(double currentPsi, Coord Path, Coord Car);
	Coord calcCarToPathCoordGlobal(double currentPsi, Coord Path, Coord Car);

};

