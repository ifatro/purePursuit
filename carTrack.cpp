#include "carTrack.h"
#include "config.h"


carTrack::carTrack()
{
	carLength = fordFusionLength;
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

void carTrack::calcWheelAngCmd(Coord pathinCarCoord)
{

	double alfa;

	alfa = atan2(pathinCarCoord.y, pathinCarCoord.x);
	TurnRadius= fabs(lookAheadRange / (2 * sin(alfa)));
	WheelAngCmd = atan(2 * carLength * sin(alfa) / lookAheadRange);



}
