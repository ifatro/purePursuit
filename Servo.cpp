#include <math.h>
#include "Servo.h"

#define PI 3.14159265359


Servo::Servo()
{

	lamdaAngLimiter = 45*PI/180; // wheel angle mechanical limit is 45 [degress]
	lamdaRateLimiter = 20*PI/180; // wheel rate limit is 20 deg/sec
	lamdaMeas = 0;
	lamdaMeasPrev = 0;
}

Servo::Servo(double lamdaAngLimiter1, double lamdaRateLimiter1)
{
	lamdaAngLimiter = lamdaAngLimiter1;
	lamdaRateLimiter = lamdaRateLimiter1;
	lamdaMeas = 0;
	lamdaMeasPrev = 0;

}

void Servo::simpleServo(double lamdaCmd)
{



	if (fabs(lamdaCmd) > lamdaAngLimiter)
	
	{
		if (lamdaCmd > 0)
		{

			lamdaMeas = lamdaAngLimiter;
		}
		else
		{

			lamdaMeas = -lamdaAngLimiter ;

		}



	}

	else

	{
		lamdaMeas = lamdaCmd;

	}
	

	
}

void Servo::fullServo(double lamdaCmd)
{

	lamdaMeas = lamdaCmd;
}



