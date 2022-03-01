#include "Rotations.h"
#include "Coord.h"
#include <math.h>



Coord Rotations::calcPathCoordGlobalToCar(double currentPsi, Coord Path, Coord Car)
{

	Coord PathToCarTranslation;
	Coord PathGlobalToCar;


	PathToCarTranslation.x = Path.x - Car.x;
	PathToCarTranslation.y = Path.y - Car.y;
	PathToCarTranslation.z = Path.z - Car.z;


	PathGlobalToCar.x = PathToCarTranslation.x * cos(currentPsi) + PathToCarTranslation.y * sin(currentPsi);
	PathGlobalToCar.y = -PathToCarTranslation.x * sin(currentPsi) + PathToCarTranslation.y * cos(currentPsi);
	PathGlobalToCar.z = PathToCarTranslation.z;
	return PathGlobalToCar;
}

Coord Rotations::calcCarToPathCoordGlobal(double currentPsi, Coord Path, Coord Car)
{


	Coord CarToPathGlobal;


	CarToPathGlobal.x = Path.x * cos(currentPsi) - Path.y * sin(currentPsi);
	CarToPathGlobal.y = Path.x * sin(currentPsi) + Path.y * cos(currentPsi);
	CarToPathGlobal.z = Path.z;





	CarToPathGlobal.x = CarToPathGlobal.x + Car.x;
	CarToPathGlobal.y = CarToPathGlobal.y + Car.y;
	CarToPathGlobal.z = CarToPathGlobal.z + Car.z;



	return CarToPathGlobal;



}


