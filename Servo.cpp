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


	 //              0.1736 z ^ 2 + 0.3471 z + 0.1736
	//	z ^ (-2) * ------------------------------
	//	           z ^ 2 - 0.5322 z + 0.2265



	a = 0.1736;
	b = 0.3471;
	c = 0.1736;
	d = 0.5322;
	e = 0.2265;


}

/*Servo::Servo(double lamdaAngLimiter1, double lamdaRateLimiter1)
{
	lamdaAngLimiter = lamdaAngLimiter1;
	lamdaRateLimiter = lamdaRateLimiter1;
	lamdaMeas = 0;
	lamdaMeasPrev = 0;


	//sevo second degree filter parameters:
	inPrev = 0;
	inPrevPrev = 0;
	outPrev = 0;
	outPrevPrev = 0;


	//              0.1736 z ^ 2 + 0.3471 z + 0.1736
   //	z ^ (-2) * ------------------------------
   //	           z ^ 2 - 0.5322 z + 0.2265

	a = 0.1736;
	b = 0.3471;
	c = 0.1736;
	d = 0.5322;
	e = 0.2265;



}*/

double Servo::limiterServo(double lamdaCmdIn)
{


	double lamdaCmdOut;
	lamdaCmdOut = lamdaCmdIn;

	if (fabs(lamdaCmdIn) > lamdaAngLimiter)

	{
		if (lamdaCmdIn > 0)
		{

			lamdaCmdOut = lamdaAngLimiter;
		}
		else
		{

			lamdaCmdOut = -lamdaAngLimiter;
		}
	}

	return lamdaCmdOut;

}

double Servo::limiterRateServo(double lamdaCmdIn)
{
	double lamdaCmdOut;

	lamdaCmdOut = lamdaCmdIn;

	if (fabs(lamdaCmdIn - lamdaMeasPrev)> lamdaRateLimiter*dt)
	{
		if (lamdaCmdIn > lamdaMeasPrev)
		{
			lamdaCmdOut = lamdaMeasPrev + lamdaRateLimiter * dt;
		}

		if (lamdaCmdIn < lamdaMeasPrev)
		{
			lamdaCmdOut = lamdaMeasPrev - lamdaRateLimiter * dt;
		}

	}

	return lamdaCmdOut;
}

void Servo::fullServo(double lamdaCmd)
{
	lamdaMeas = limiterRateServo(lamdaCmd);
	lamdaMeas = controllerServo(lamdaMeas);
	lamdaMeas = limiterServo(lamdaMeas);
	lamdaMeasPrev = lamdaMeas;


	lamdaMeas = lamdaCmd;

}

double  Servo::controllerServo(double lamdaIn)
{
	
	double lamdaOut;

	/*F = 2;
	w = 2 * pi * F;
	Z = 0.7
		T_smp = 1 / 10;
	s = tf('s');
	FP_cont = exp(-0.2 * s) * 1 / (s ^ 2 / w ^ 2 + (2 * Z / w) * s + 1);
	FP_dis = c2d(FP_cont, T_smp, 'tustin')


		FP_dis =

					0.1736 z ^ 2 + 0.3471 z + 0.1736
		z ^ (-2) * ------------------------------
				   z ^ 2 - 0.5322 z + 0.2265

*/

	lamdaOut = a * lamdaIn + b * inPrev + c * inPrevPrev + d * outPrev - e * outPrevPrev;

	outPrevPrev = outPrev;
	outPrev = lamdaOut;
	inPrevPrev = inPrev;
	inPrev = lamdaIn;

	return lamdaOut;


}



