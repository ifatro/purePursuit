#pragma once
#include "Coord.h"
class Path
{
	
	
/*--------------------------------------------------------------------------------------------------
Path class encapsulates the road cartesian coordinates in a global system :
There are two path typs: 1- stright line; 2- circle.
The  length of the path in is defined in the main() function.
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

