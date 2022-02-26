#pragma once
#include "Coord.h"
#include "Servo.h"

class Car
{


public:

	Car();
	Car(double initPsi);
	void calcWheelAngCmd(Coord PathInCarCoord);
	void updateCarDynamics();
	Coord globalCoord;
	Coord egoCoord;
	Servo carServo;
	double velocity;
	double carLength;
	double psi;
	
	double lookAheadRange;
	double TurnRadius;
	double WheelAngCmd;

protected:
	double psi_dot; //angular velocity
	double x_dot;
	double y_dot;
};

