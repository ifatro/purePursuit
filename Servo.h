#pragma once
class Servo
{

public:


	Servo();
	Servo(double lamdaAngLimiter1, double lamdaRateLimiter1);


	double lamdaMeas;
	void limiterServo(double lamdaCmd);
	void fullServo(double lamdaCmd);

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

