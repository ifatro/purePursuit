#include "config.h"
#include "Car.h"
#include "Servo.h"
#include <math.h>
Car::Car(double initPsi)
{

	psi = initPsi;
	velocity=5;
	psi_dot = 0;
	x_dot=0;
	y_dot = 0;
	carLength = fordFusionLength;
	lookAheadRange = 30;
	carTrack carTrack1(carLength, lookAheadRange);
	



}


void Car::updateCarDynamics()
{

	double lamda;
	lamda=this->carServo.lamdaPhys;
	this->psi_dot = this->velocity * tan(lamda) / this->carLength;
	this->x_dot = this->velocity * cos(this->psi);
	this->y_dot = this->velocity * sin(this->psi);

	this->psi = this->psi + dt * this->psi_dot;
	this->psi = fmod(this->psi, 2 * PI);

	this->globalCoord.x = this->globalCoord.x + dt* this->x_dot;
	this->globalCoord.y = this->globalCoord.y + dt * this->y_dot;




}
