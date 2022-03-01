#include "Path.h"
#include <math.h>
#include <iostream>
#include "config.h"
Path::Path(unsigned int Type1, unsigned int pathLength1)
{
	Type = Type1; //There are two path typs: 1- stright line; 2- circle.
	pathLength = pathLength1;
	generatePath();
}

void Path::printPath(void)
{
	unsigned int i;
	for (i = 0; i<pathLength; i++)
	{
		std::cout << i << "x: " << iPath[i].x << " y: " << iPath[i].y << " z: " << iPath[i].z << "\n";
	}
}

void Path::generatePath()
{
	unsigned int i = 0;
	iPath = new Coord[pathLength];
	if (Type==1) // line
	{
		
		for (i = 0; i < pathLength; i++)
		{
			iPath[i].x = double(i * 2);
			iPath[i].y = (double)i * 2;
			iPath[i].z = 0;
		}
	}
	else
	{
		// circle
		for (i = 0; i < pathLength; i++)
		{



			double omega = 0.005;
			double rad = 200;
			iPath[i].x = rad*double(cos(omega*PI*i))-rad;
			iPath[i].y = rad*double(sin(omega *PI *i));
			iPath[i].z = 0;
		}
	}

}

