#include <math.h>
#include "config.h"
#include "Servo.h"




Servo::Servo()
{
	// Second degree cntroller parameters
	


	//servo constructor:


	lamdaAngLimiter = specLamdaAngLimiter; // wheel angle mechanical limit is 45 [degress]
	lamdaRateLimiter = specLlamdaRateLimiter; // wheel rate limit is 20 deg/sec
	lamdaPhys = 0;        // Initial wheel angle 
	lamdaPhysPrev = 0;   // Initial wheel angle 


	//sevo second degree filter parameters initialization:
	inPrev=0;
	inPrevPrev = 0;
	outPrev = 0;
	outPrevPrev = 0;


	//Second order filter parameters with sample time of dt=0.1[sec]

	 //              0.1736 z ^ 2 + 0.3471 z + 0.1736
	//	            ------------------------------
	//	           z ^ 2 - 0.5322 z + 0.2265



	a = 0.1736;
	b = 0.3471;
	c = 0.1736;
	d = 0.5322;
	e = 0.2265;


}



double Servo::limiterServo(double lamdaCmdIn)
{
	/*This function is used to model a mechanical limiter*/


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
	/*This function is used to model a rate limiter*/
	double lamdaCmdOut;

	lamdaCmdOut = lamdaCmdIn;

	if (fabs(lamdaCmdIn - lamdaPhysPrev)> lamdaRateLimiter*dt)
	{
		if (lamdaCmdIn > lamdaPhysPrev)
		{
			lamdaCmdOut = lamdaPhysPrev + lamdaRateLimiter * dt;
		}

		if (lamdaCmdIn < lamdaPhysPrev)
		{
			lamdaCmdOut = lamdaPhysPrev - lamdaRateLimiter * dt;
		}

	}

	return lamdaCmdOut;
}

void Servo::fullServo(double lamdaCmd)
{
	lamdaPhys = limiterRateServo(lamdaCmd);
	lamdaPhys = controllerServo(lamdaPhys);
	lamdaPhys = limiterServo(lamdaPhys);
	lamdaPhysPrev = lamdaPhys;
	lamdaPhys = lamdaCmd;


}

double  Servo::controllerServo(double lamdaIn)
{

	/*This function is used to model a closed loop servo-mechanical actuator between the command and
     the actual road wheel angle as a second order filter with a bandwidth of 2[Hz].
	The function calculates a second order discrete filter output with a sampling time of 10[Hz] and  a damping factor, ζ (zeta)=0.7.
	The filter input is the lamda wheel command.
	*/
	
	double lamdaOut;

	/*
	* 
		FP_dis =

					0.1736 z ^ 2 + 0.3471 z + 0.1736
		             ------------------------------
				   z ^ 2 - 0.5322 z + 0.2265
*/

	lamdaOut = a * lamdaIn + b * inPrev + c * inPrevPrev + d * outPrev - e * outPrevPrev;

	outPrevPrev = outPrev;
	outPrev = lamdaOut;
	inPrevPrev = inPrev;
	inPrev = lamdaIn;

	return lamdaOut;


}



