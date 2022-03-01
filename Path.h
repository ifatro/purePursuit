#pragma once
#include "Coord.h"
class Path
{

	/*--------------------------------------------------------------------------------------------------
Path class encapsulates the road cartesian coordinates in a global system :

--------------------------------------------------------------------------------------------------*/


public:

	Path();
	Path(unsigned int Type1, unsigned int pathLength1);
	unsigned int Type;
	unsigned int pathLength;
	Coord globalCoord;
	Coord egoCoord;
	Coord* iPath;
	void printPath(void);



private:
	void generatePath(void);


};

