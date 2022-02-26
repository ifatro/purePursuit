#pragma once
#include "Coord.h"
#include "Servo.h"
#include "carTrack.h"
/* Car class encapsulates car functionality :
   car servo
   car mechanical parameters
   car dynamics */

class Car
{


public:

	Car();
	Car(double initPsi);
	void updateCarDynamics();
	Coord globalCoord;
	Coord egoCoord;
	Servo carServo;
	double velocity;
	double psi;
	double lookAheadRange;
	double carLength;
	carTrack carTrack1;

protected:
	double psi_dot; //angular velocity
	double x_dot;
	double y_dot;
};

