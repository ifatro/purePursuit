#pragma once
#include <math.h>
#include "Coord.h"
class carTrack

	/*--------------------------------------------------------------------------------------------------
	CarTrack class encapsulates a basic car tracking functionality:
    from  road analysis to generation of the wheel command.
	The carTrack class main function calcWheelAngCmd(Coord *) receives the following inputs:
	1. pathinCarCoord- required coordinate point in the car coordinate system of the look ahead point
	2. lookAheadRange
	3. carLength
	and calculates:
	1. TurnRadius - the turn radius required to reach the look ahead point
	2. WheelAngCmd - rhe wheel angle command
	--------------------------------------------------------------------------------------------------*/

{

public:
	carTrack();
	carTrack(double carLength1, double lookAheadRange1);
	void calcWheelAngCmd(Coord pathinCarCoord);

	
	double TurnRadius;
	double WheelAngCmd;


private:
	double lookAheadRange;
	double carLength;
};

