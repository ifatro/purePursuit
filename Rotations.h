#pragma once
#include <math.h>
#include "Coord.h"


/*--------------------------------------------------------------------------------------------------
Rotation class encapsulates the rotation from the path global coordinate system to the car coordinate system 
                       and  the rotation from  the car coordinate systemthe to the path global coordinate system 
using functions:

1.calcPathCoordGlobalToCar - rotation from path global system to car system
2.calcCarToPathCoordGlobal - rotation from car system to path global system

Inputs:
currentPsi - current car psi angle in global coordinate system
Path - path pos. car/global coordinate system.
Car - car pos. in global coordinate system.
--------------------------------------------------------------------------------------------------*/

class Rotations
{

public:


	Coord calcPathCoordGlobalToCar(double currentPsi, Coord Path, Coord Car);
	Coord calcCarToPathCoordGlobal(double currentPsi, Coord Path, Coord Car);

};

