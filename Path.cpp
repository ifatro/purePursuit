#include "Path.h"
#include <math.h>
#include <iostream>

Path::Path(unsigned int Type1, unsigned int pathLength1)
{
	Type = Type1;
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
	if (Type==1)
	{
		// line
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



			/*% circle
				r = 500;
			th = 0:pi / 10000 : 2 * pi;
			xunit = r * cos(th) - r;
			yunit = r * sin(th);
			Path.x = xunit;
			Path.y = yunit;
			Path.z = 0;*/


			double omega = 0.01;
			double rad = 500;
			iPath[i].x = rad*double(cos(omega*3.14*i))-rad;
			iPath[i].y = rad*double(sin(omega * 3.14 *i));
			iPath[i].z = 0;
		}
	}

}

