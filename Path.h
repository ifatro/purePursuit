#pragma once
#include "Coord.h"
class Path
{
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

