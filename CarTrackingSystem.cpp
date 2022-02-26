#include "CarTrackingSystem.h"
#include "Coord.h"
#include "Car.h"
#include "Path.h"
#include "Rotations.h"

CarTrackingSystem::CarTrackingSystem(Car* honda1, Path* road1)
{
	road = road1;
	honda = honda1;
	lastPathIndex = 1;
}





bool CarTrackingSystem::CalcLookAheadCoord()
{

	Rotations Rot;
	Coord currPos = honda->globalCoord;

	unsigned int i;
	bool found = false;
//	Coord PathinCarCoord;



	for(i=lastPathIndex; i< road->pathLength -1 && !found; i++)
	{

		Coord PathinCar;
		Coord PathinCarNext;


		PathinCar=Rot.calcPathCoordGlobalToCar(honda->psi, road->iPath[i]  ,honda->globalCoord );
		PathinCarNext=Rot.calcPathCoordGlobalToCar(honda->psi, road->iPath[i + 1], honda->globalCoord);

	
		if (checkForLookaheadIntersection(PathinCar, PathinCarNext, honda->lookAheadRange))
		{
			found = true;
			lastPathIndex = i;
			PathInCarCoord = PathinCarNext;
		}
	}


	return found;

}

bool CarTrackingSystem::checkForLookaheadIntersection(Coord a, Coord b, double lookAheadRange)
{ 
	double aRange;
	double bRange;


	aRange = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	bRange = sqrt(b.x * b.x + b.y * b.y + b.z * b.z);
	
	if (aRange<lookAheadRange && bRange>lookAheadRange)
	{

		return true;

	}
	

	return false;


}






