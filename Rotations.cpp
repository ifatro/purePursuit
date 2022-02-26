#include "Rotations.h"
#include "Coord.h"
#include <math.h>



/*void Rotations::calcRot(double psi)
{

	C_Global2Car[0][0] = cos(psi);
	C_Global2Car[0][1] = sin(psi);
	C_Global2Car[0][2] = 0;
	C_Global2Car[1][0] = -sin(psi);
	C_Global2Car[1][1] = cos(psi);
	C_Global2Car[1][2] = 0;
	C_Global2Car[2][0] = 0;
	C_Global2Car[2][1] = 0;
	C_Global2Car[2][2] = 1;


	C_Car2Global[0][0] = cos(psi);
	C_Car2Global[0][1] = -sin(psi);
	C_Car2Global[0][2] = 0;
	C_Car2Global[1][0] = sin(psi);
	C_Car2Global[1][1] = cos(psi);
	C_Car2Global[1][2] = 0;
	C_Car2Global[2][0] = 0;
	C_Car2Global[2][1] = 0;
	C_Car2Global[2][2] = 1;


}*/

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


