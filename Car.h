#pragma once
#include "Coord.h"
#include "Servo.h"
#include "carTrack.h"

/*--------------------------------------------------------------------------------------------------
Car class encapsulates car functionality :
   1. car servo - class encapsulate wheel dynamics from command to physical and measure
   2. car basic tracking system - class encapsulates road analysis to generate wheel command
   3. car mechanical parameters : car length[meter], velocity[m/sec]
   4. car input dynamics -initial position, initial angles (psi), velocity,
   5. car coordinates - usind Coord class
   6. car dynamic update - updates the position, rates  and angular states of the car.

--------------------------------------------------------------------------------------------------*/

class Car
{


public:

	Car();
	Car(double initPsi);
	void updateCarDynamics();
	Coord globalCoord;
	Coord egoCoord;
	Servo carServo;
	carTrack basicCarTrack;
	double velocity;
	double psi;
	double lookAheadRange;
	double carLength;
	

protected:
	//car dynamic states are protected
	double psi_dot; //car angular velocity in the psi direction
	double x_dot;   // x dot car state
	double y_dot;   // y dot car state
};

