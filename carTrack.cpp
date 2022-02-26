#include "carTrack.h"



carTrack::carTrack()
{
	carLength = 1;
	lookAheadRange = 30;
	TurnRadius = 10000;
	WheelAngCmd = 0;

}

carTrack::carTrack(double carLength1, double lookAheadRange1)
{
	carLength = carLength1;
	lookAheadRange = lookAheadRange1;
	TurnRadius = 10000;
	WheelAngCmd = 0;
}

void carTrack::calcWheelAngCmd(Coord PathInCarCoord)
{

	double alfa;

	alfa = atan2(PathInCarCoord.y, PathInCarCoord.x);
	TurnRadius= fabs(lookAheadRange / (2 * sin(alfa)));
	WheelAngCmd = atan(2 * carLength * sin(alfa) / lookAheadRange);



}
