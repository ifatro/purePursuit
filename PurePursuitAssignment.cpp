// PurePursuitAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
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




int main()
{

    double initPsi_deg;

    
    unsigned int pathType;

 
    
    bool pathFound=true;

    std::cout << "Enter Initial car psi [deg]:\n";
    std::cin >> initPsi_deg;
    std::cout << "Enter Path Type (1 for line, 2 for circle):\n";
    std::cin >> pathType;

    Car Honda(initPsi_deg * DEG2RAD);
    Path Road(pathType,1000);
    SimulatedTrackingLookAheadPoint SimulatedTrackingLookAheadPoint1(&Honda, &Road);

;



    double T;

    for (T = 0; T < simulationTime && pathFound; T=T+dt)
    {


        SimulatedTrackingLookAheadPoint1.SetLocalizationErr(false);
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
            std::cout << "index: ";
            std::cout << index;
            std::cout << "\n";
            std::cout << "WheelAngCmd: ";
            std::cout << Honda.basicCarTrack.WheelAngCmd * RAD2DEG;
            std::cout << "\n";

        }
    }




}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
