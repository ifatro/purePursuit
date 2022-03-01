// mainPurePursuitAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "config.h"
#include "Car.h"
#include "Coord.h"
#include "Path.h"
#include "Rotations.h"
#include "SimulatedTrackingLookAheadPoint.h"


/*------------------------------------------------------------------------------------------------------------
mainPurePursuitAssignment is the main function which runs the pursuit tracking algorithm.

* The inputs to the simulation are given by the user in the console:

- initial car psi angle [deg]
- The type of the road path:straight(1)/circle(2)


The simulation runs for simulation Time=200[sec] with dt=0.1[sec]  both set in config.h

* THe steps of the simulation are as follows:

a. SimulatedTrackingLookAheadPoint1.SetLocalizationErr(true/false)- set INS noise (default is false)
b. SimulatedTrackingLookAheadPoint1.CalcLookAheadCoord(*) - calcultes lookahead point in path.
c. Honda.basicCarTrack.calcWheelAngCmd(*) - calculates  wheel angle command
d. Honda.carServo.fullServo(*) - calculates servo command to physical servo.
e. Honda.updateCarDynamics() - updates the dynamics of the car.

The simulation prints the followong outputs
------------------------------------------------------------------------------------------------------------*/


int main()
{

    double initPsi_deg;
    unsigned int pathType;

 
    
    bool pathFound=true;

    std::cout << "Enter Initial car psi [deg]:\n";
    std::cin >> initPsi_deg;
    std::cout << "Enter Path Type (1 for line, 2 for circle):\n";
    std::cin >> pathType;


    // Objects initialization

    Car Honda(initPsi_deg * DEG2RAD);
    Path Road(pathType,1000);
    SimulatedTrackingLookAheadPoint SimulatedTrackingLookAheadPoint1(&Honda, &Road);
    SimulatedTrackingLookAheadPoint1.SetLocalizationErr(false);






    for (double T = 0; T < simulationTime && pathFound; T=T+dt)
    {

        
        pathFound = SimulatedTrackingLookAheadPoint1.CalcLookAheadCoord();
        if (pathFound)
        {
            Honda.basicCarTrack.calcWheelAngCmd(SimulatedTrackingLookAheadPoint1.pathinCarCoord);
            Honda.carServo.fullServo(Honda.basicCarTrack.WheelAngCmd);
            Honda.updateCarDynamics();







            // Prints:
            unsigned int index;
            Coord PathInGlobalCoord;
            index = SimulatedTrackingLookAheadPoint1.lastPathIndex;
            PathInGlobalCoord.x = Road.iPath[index].x;
            PathInGlobalCoord.y = Road.iPath[index].y;
            PathInGlobalCoord.z = Road.iPath[index].z;
            double diff = sqrt((Honda.globalCoord.z - PathInGlobalCoord.z) * (Honda.globalCoord.z - PathInGlobalCoord.z) + (Honda.globalCoord.y - PathInGlobalCoord.y) * (Honda.globalCoord.y - PathInGlobalCoord.y));
            std::cout << "(Honda-Path): ";
            std::cout << diff;
            std::cout << "\n";
            std::cout << "car psi: ";
            std::cout << Honda.psi * RAD2DEG;
            std::cout << "\n";
            std::cout << "simulation time: ";
            std::cout << T;
            std::cout << "\n";
            std::cout << "WheelAngCmd: ";
            std::cout << Honda.basicCarTrack.WheelAngCmd * RAD2DEG;
            std::cout << "\n";

        }
    }
}



