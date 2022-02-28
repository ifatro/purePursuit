#include "config.h"
#include "Car.h"
#include "Servo.h"
#include <math.h>
Car::Car(double initPsi)
{

	psi = initPsi;
	velocity=20;
	psi_dot = 0;
	x_dot=0;
	y_dot = 0;
	carLength = fordFusionLength;
	lookAheadRange = 30;
	carTrack carTrack1(carLength, lookAheadRange);
	



}

/*void Car::calcWheelAngCmd(Coord PathInCarCoord)
{

	double alfa;

	alfa = atan2(PathInCarCoord.y, PathInCarCoord.x);
	this->TurnRadius = fabs(this->lookAheadRange/ (2 * sin(alfa)));
	this->WheelAngCmd = atan(2 * this->carLength * sin(alfa) / this->lookAheadRange);

	/* [az el ld] = rned2azelr(TP);

	% Usage: [az, el, rlos] = rned2azelr(Rned)

    rlos = double(sqrt(Rned(1) ^ 2 + Rned(2) ^ 2 + Rned(3) ^ 2));
	az = double(atan2(Rned(2), Rned(1)));
	el = double(-asin(Rned(3) / rlos));

	alfa = az;% pi / 2;
	inf = 1 * pi / 180;
	if (abs(alfa) >= pi - inf)
		msgbox('Error in path');
	return;
	end
		Radius = abs(ld / (2 * sin(alfa)));
	lamda = atan(2 * L * sin(alfa) / ld);


}
*/


void Car::updateCarDynamics()
{

	double lamda;
	lamda=this->carServo.lamdaMeas;
	this->psi_dot = this->velocity * tan(lamda) / this->carLength;
	this->x_dot = this->velocity * cos(this->psi);
	this->y_dot = this->velocity * sin(this->psi);

	this->psi = this->psi + dt * this->psi_dot;

	this->psi = fmod(this->psi, 2 * PI);

	this->globalCoord.x = this->globalCoord.x + dt* this->x_dot;
	this->globalCoord.y = this->globalCoord.y + dt * this->y_dot;





	/*lamda = Car.lamdaDyn;
	v = Car.v;
	L = Car.L;
	x = Car.x;
	y = Car.y;
	psi = Car.psi;

	psi_dot = v * tan(lamda) / L;
	psi = psi + dt * psi_dot;
	psi = Handlepsi(psi);
	x_dot = v * cos(psi);
	y_dot = v * sin(psi);
	x = x + dt * x_dot;
	y = y + dt * y_dot;


	double x_dot;
	double y_dot;
	double psi_dot;*/



}
