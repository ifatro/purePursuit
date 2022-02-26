#pragma once
#include "Coord.h"
#include "Car.h"
#include "Path.h"
#include "Rotations.h"

class SimulatedTrackingSystem
{
public:

	SimulatedTrackingSystem(Car* honda1, Path* road1);

	unsigned int lastPathIndex;

	bool CalcLookAheadCoord();

	bool checkForLookaheadIntersection(Coord a, Coord b, double lookAheadRange);
	
	Coord PathInCarCoord;

private:

	Path* road;
	Car* honda;

};

