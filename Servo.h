#pragma once
class Servo
{

public:


	Servo();
	Servo(double lamdaAngLimiter1, double lamdaRateLimiter1);


	double lamdaMeas;
	void simpleServo(double lamdaCmd);
	void fullServo(double lamdaCmd);

protected:

	double lamdaAngLimiter;
	double lamdaRateLimiter;

};

