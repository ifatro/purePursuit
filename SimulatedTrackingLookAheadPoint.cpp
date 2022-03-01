#include <random>
#include "config.h"
#include "SimulatedTrackingLookAheadPoint.h"
#include "Coord.h"
#include "Car.h"
#include "Path.h"
#include "Rotations.h"



SimulatedTrackingLookAheadPoint::SimulatedTrackingLookAheadPoint(Car* honda1, Path* road1)
{
	road = road1;
	honda = honda1;
	lastPathIndex = 1;
	applyLocalizationErr=false;
}

void SimulatedTrackingLookAheadPoint::SetLocalizationErr(bool applyLocalizationErr1)
{

	applyLocalizationErr = applyLocalizationErr1;
}





bool SimulatedTrackingLookAheadPoint::CalcLookAheadCoord()
{

	Rotations Rot;
	Coord currPos = honda->globalCoord;

	unsigned int i;
	bool found = false;
//	Coord pathinCarCoord;



	for(i=lastPathIndex; i< road->pathLength -1 && !found; i++)
	{

		Coord pathinCar;
		Coord pathinCarNext;

		if (applyLocalizationErr)
		{
			double randnPsi = honda->psi+rand();
			Coord randniPath;
			
	


			std::default_random_engine generator;
			std::normal_distribution<double> distPos(0, gpsStdPos); // Adding white noise to position with standard deviation of 0.1[meter]
			std::normal_distribution<double> distAng(0, gpsStdAng);// Adding white noise to angle with standard deviation of 0.01[rad]
			

			randniPath.x= honda->globalCoord.x + distPos(generator);
			randniPath.y = honda->globalCoord.y + distPos(generator);
			randniPath.z = honda->globalCoord.z + distPos(generator);

			pathinCar = Rot.calcPathCoordGlobalToCar(honda->psi, road->iPath[i], randniPath);
			pathinCarNext = Rot.calcPathCoordGlobalToCar(honda->psi, road->iPath[i + 1], honda->globalCoord);

		}
		else
		{
			pathinCar = Rot.calcPathCoordGlobalToCar(honda->psi, road->iPath[i], honda->globalCoord);
			pathinCarNext = Rot.calcPathCoordGlobalToCar(honda->psi, road->iPath[i + 1], honda->globalCoord);
		}


	
		if (checkForLookaheadIntersection(pathinCar, pathinCarNext, honda->lookAheadRange))
		{
			found = true;
			lastPathIndex = i;
			pathinCarCoord = pathinCarNext;
		}
	}


	return found;

}

bool SimulatedTrackingLookAheadPoint::checkForLookaheadIntersection(Coord pathinCar, Coord pathinCarNext, double lookAheadRange)
{ 
	double aRange;
	double bRange;


	aRange = sqrt(pathinCar.x * pathinCar.x + pathinCar.y * pathinCar.y + pathinCar.z * pathinCar.z);
	bRange = sqrt(pathinCarNext.x * pathinCarNext.x + pathinCarNext.y * pathinCarNext.y + pathinCarNext.z * pathinCarNext.z);
	
	if (aRange<lookAheadRange && bRange>lookAheadRange)
	{

		return true;

	}
	

	return false;


}






