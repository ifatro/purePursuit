#include <math.h>
#include "config.h"
#include "Servo.h"




Servo::Servo()
{
	// Second degree cntroller parameters
	

//	#define specLamdaAngLimiter = 45 * PI / 180; // wheel angle mechanical limit is 45 [degress]
//#define specLlamdaRateLimiter = 20 * PI / 180; // wheel rate limit is 20 deg/sec



	lamdaAngLimiter = specLamdaAngLimiter; // wheel angle mechanical limit is 45 [degress]
	lamdaRateLimiter = specLlamdaRateLimiter; // wheel rate limit is 20 deg/sec
	lamdaPhys = 0;
	lamdaPhysPrev = 0;


	//sevo second degree filter parameters:
	inPrev=0;
	inPrevPrev = 0;
	outPrev = 0;
	outPrevPrev = 0;


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

	/*F = 2;
	w = 2 * pi * F;
	Z = 0.7
		T_smp = 1 / 10;
	s = tf('s');
	FP_cont = exp(-0.2 * s) * 1 / (s ^ 2 / w ^ 2 + (2 * Z / w) * s + 1);
	FP_dis = c2d(FP_cont, T_smp, 'tustin')


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



