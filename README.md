# purePursuit

mainPurePursuitAssignment is the main function which runs the pursuit tracking algorithm.

* Two inputs to the simulation are received from the user in the console application:

- The initial car psi angle [deg]
- The type of the road path:straight(1)/circle(2)

The simulation runs for  Time=200[sec] with dt=0.1[sec] -  both are set in config.h.

* The steps of the simulation are as follows:


    
a. SimulatedTrackingLookAheadPoint1.CalcLookAheadCoord(*) 
    - calculates the lookahead point in path.
    
b. Honda.basicCarTrack.calcWheelAngCmd(*)  - calculates  wheel angle command.

c. Honda.carServo.fullServo(*) - calculates the transfer function from the servo command to the physical servo.

d. Honda.updateCarDynamics()   - updates the dynamics of the car.

The simulation prints a few chosen outputs.


-----------------------------------------------------------------------------------

Car class encapsulates car functionality :

1. car servo - the class encapsulate the wheel dynamics from command to physical wheel.

2. car basic tracking system - the class encapsulates the road analysis to generate wheel command.

3. car mechanical parameters - car length[meter], velocity[m/sec]
 
4. car input dynamics -initial position, initial angles (only psi), velocity.

5. car coordinates - using Coord class.

6. car dynamic update - updates the position, rates  and angular states of the car.

----------------------------------------------------------------------------------



CarTrack class encapsulates a basic car tracking functionality:
from  road analysis to generation of the wheel command.
The carTrack class main function calcWheelAngCmd(Coord *) receives the following inputs:

	1. pathinCarCoord- required coordinate point in the car coordinate system of the lookahead point.
	
	2. lookAheadRange - lookahead range.
	
	3. carLength - car length parameter according to the kinematic bicycle model is set in the config.h file.
	
and calculates:

	1. TurnRadius - the turn radius required to reach the lookahead point.
	
	2. WheelAngCmd - the required wheel angle  command.

  
------------------------------------------------------------------------------------

Path class encapsulates the road cartesian coordinates in a global system :
There are two path typs: 

1- stright line

2- circle

The  length of the path is defined in the main() function.



-----------------------------------------------------------------------------------------

Rotation class encapsulates the rotation from the path global coordinate system to the car coordinate system 
and  the rotation from  the car coordinate systemthe to the path global coordinate system 

functions:

1.calcPathCoordGlobalToCar - rotation from path global system to car system.
2.calcCarToPathCoordGlobal - rotation from car system to path global system.

Inputs:

currentPsi - current car psi angle in global coordinate system.

Path - path pos. car/global coordinate system.

Car - car pos. in global coordinate system.

----------------------------------------------------------------------------------



Servo class encapsulates the model of the  closed loop servo-mechanical actuator between the command and
     the actual road wheel angle with the functionality:

1. limiterRateServo - limit wheel rate according to the specification in config.h.

2. controllerServo  - second order filter with 2[Hz] bandwidth and sampling time of 10[Hz].

3. limiterServo     - mechanical angle limiter according to the specification in config.h.


Output: 
	 lamdaPhys - physical lamda wheel angle.
	 
--------------------------------------------------------------------------


SimulatedTrackingLookAheadPoint class encapsulates the simulation of an etity that generates the 
lookahead point of the path in the car coordinate system and is an input to the car track object.
The entity is a simulation of an INS (Inertial Navigation System) that uses GPS and rate gyros.
This entity main function checkForLookaheadIntersection(Coord *, Coord *, double *)
calculates the closest point in the path/road in which the distance from the car to the path is
larger than the lookAheadRange paramater.
The inputs of the function:

1. pathinCar - Path point in car coordinate system

2. pathinCarNext - Next path point in car coordinate system
 
3. lookAheadRange - The  range to which a path point is requested. the lookahead range is a parameter of the car track system.

The output of the function:

1. pathinCarCoord - the requested path point that fullfils the lookahead range parameter request.

There is an option to add localizations error in the INS/GYRO according to the config file specification
using the flag indicating localization noise addition:

applyLocalizationErr  true/false in config.h

---------------------------------------------------------------------------

config.h - configuration file.
