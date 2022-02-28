#pragma once
class Servo
{

public:


	Servo();
	//Servo(double lamdaAngLimiter1, double lamdaRateLimiter1);


	double lamdaMeas;
	double limiterRateServo(double lamdaCmdIn);
	double limiterServo(double lamdaCmdIn);
	void fullServo(double lamdaCmd);
	double  controllerServo(double lamdaIn);

protected:

	double lamdaAngLimiter;
	double lamdaRateLimiter;
	double lamdaMeasPrev;

	double inPrev;
	double inPrevPrev;
	double outPrev;
	double outPrevPrev;
	double a,b,c,d,e;
};

