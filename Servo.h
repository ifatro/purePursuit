#pragma once
class Servo
{


	/*--------------------------------------------------------------------------------------------------
Servo class encapsulates the model of the  closed loop servo-mechanical actuator between the command and
     the actual road wheel angle with the functionality:

	 1. limiterRateServo - limit wheel rate according to specification.
	 2. controllerServo - second order filter with 2[Hz] bandwidth.
	 3. limiterServo - mechanical angle limit.


	 Output: 
	 lamdaPhys - physical lamda wheel angle.
--------------------------------------------------------------------------------------------------*/

public:


	Servo();



	double lamdaPhys;
	double limiterRateServo(double lamdaCmdIn);
	double limiterServo(double lamdaCmdIn);
	void fullServo(double lamdaCmd);
	double  controllerServo(double lamdaIn);

protected:

	double lamdaAngLimiter;    // mechanical wheel limiter parameter.
	double lamdaRateLimiter;   // wheel rate limiter parameter.
	double lamdaPhysPrev;      // previous physical lamda wheel angle.
	double inPrev;         //closed loop second order filter parameter
	double inPrevPrev;     //closed loop second order filter parameter
	double outPrev;        //closed loop second order filter parameter
	double outPrevPrev;    //closed loop second order filter parameter
	double a,b,c,d,e;      //closed loop second order filter parameters
};

