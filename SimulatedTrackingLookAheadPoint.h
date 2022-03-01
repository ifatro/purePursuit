#pragma once
#include <stdlib.h>
#include "Coord.h"
#include "Car.h"
#include "Path.h"
#include "Rotations.h"


/*--------------------------------------------------------------------------------------------------
SimulatedTrackingLookAheadPoint class encapsulates the simulation of an etity that generates the 
lookahead point of the path in the car coordinate system.
The entity is a simulation of an INS (Inertial Navigation System) that uses GPS and rate gyros.
This entity main function checkForLookaheadIntersection(Coord *, Coord *, double *)
calculates the closest point in the path/road in which the distance from the car to the path is
larger than the lookAheadRange paramater.
The inputs of the function:
1. pathinCar - Path point in car coordinate system
2. pathinCarNext - Next path point in car coordinate system
3. lookAheadRange - The  range to which a path point in requested. the lookahead range is a parameter of the car tracking system.
The output of the function:
1. pathinCarCoord - the requested path that fullfils the lookahead range parameter request.

There is an option to add localizations error in the INS according to the config file specification
using the flag indicating localization noise addition:
applyLocalizationErr  true/false

--------------------------------------------------------------------------------------------------*/

class SimulatedTrackingLookAheadPoint
{
public:

	SimulatedTrackingLookAheadPoint(Car* honda1, Path* road1);
	void SetLocalizationErr(bool applyLocalizationErr1);
	unsigned int lastPathIndex;
	bool applyLocalizationErr;

	bool CalcLookAheadCoord();

	bool checkForLookaheadIntersection(Coord pathinCar, Coord pathinCarNext, double lookAheadRange);
	
	Coord pathinCarCoord;

private:

	Path* road;
	Car* honda;

};

