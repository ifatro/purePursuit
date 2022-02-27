#include <math.h>
#include "config.h"
#include "Servo.h"




Servo::Servo()
{
	// Second degree cntroller parameters
	

	lamdaAngLimiter = 45*PI/180; // wheel angle mechanical limit is 45 [degress]
	lamdaRateLimiter = 20*PI/180; // wheel rate limit is 20 deg/sec
	lamdaMeas = 0;
	lamdaMeasPrev = 0;


	//sevo second degree filter parameters:
	inPrev=0;
	inPrevPrev = 0;
	outPrev = 0;
	outPrevPrev = 0;
	   //0.9653 z + 0.1822
		//----------------------
		//z ^ 2 + 0.1325 z + 0.015
	a = 0.044;
	b = 0.089;
	c = 0.044;
	d = 1.32;
	e = 0.50;


}

Servo::Servo(double lamdaAngLimiter1, double lamdaRateLimiter1)
{
	lamdaAngLimiter = lamdaAngLimiter1;
	lamdaRateLimiter = lamdaRateLimiter1;
	lamdaMeas = 0;
	lamdaMeasPrev = 0;

}

void Servo::limiterServo(double lamdaCmd)
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
	double Out;

	//Out =    a*lamdaCmd+b*inPrev+ c*inPrevPrev +d*outPrev -e*outPrevPrev;

	//outPrevPrev = outPrev;
	//outPrev = Out;
	//inPrevPrev = inPrev;
	///inPrev = lamdaCmd;
	Out = lamdaCmd;
	this->limiterServo(Out);



}



