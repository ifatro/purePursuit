#pragma once
#include <math.h>
#include "Coord.h"
class carTrack

{

public:
	carTrack();
	carTrack(double carLength1, double lookAheadRange1);
	void calcWheelAngCmd(Coord PathInCarCoord);

	
	double TurnRadius;
	double WheelAngCmd;


private:
	double lookAheadRange;
	double carLength;
};

