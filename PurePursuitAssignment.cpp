// PurePursuitAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include "Car.h"
#include "Coord.h"
#include "Path.h"
#include "Rotations.h"
#include "globalTrackingSystem.h"

#define PI 3.14159265359


int main()
{

    double initPsi_deg;
    double pi = 3.141592653589793;
    
    unsigned int pathType;

 
    
    bool pathFound=true;

    std::cout << "Enter Initial car psi [deg]:\n";
    std::cin >> initPsi_deg;
    std::cout << "Enter Path Type (1 for line, 2 for circle):\n";
    std::cin >> pathType;

    Car Honda(initPsi_deg * PI / 180);
    Path Road(pathType,1000);
    globalTrackingSystem globalTrackingSystem1(&Honda, &Road);


    double T;

    for (T = 0; T < 200 && pathFound; T++)
    {



        pathFound = globalTrackingSystem1.CalcLookAheadCoord();
        if (pathFound)
        {
            Honda.calcWheelAngCmd(globalTrackingSystem1.PathInCarCoord);
            Honda.updateCarDynamics();




            // Prints:


            unsigned int index;
            Coord PathInGlobalCoord;
            index = globalTrackingSystem1.lastPathIndex;
            PathInGlobalCoord.x = Road.iPath[index].x;
            PathInGlobalCoord.y = Road.iPath[index].y;
            PathInGlobalCoord.z = Road.iPath[index].z;

            double diff = sqrt((Honda.globalCoord.z - PathInGlobalCoord.z) * (Honda.globalCoord.z - PathInGlobalCoord.z) + (Honda.globalCoord.y - PathInGlobalCoord.y) * (Honda.globalCoord.y - PathInGlobalCoord.y));
            std::cout << "(Honda-Path): ";
            std::cout << diff;
            std::cout << "\n";
            std::cout << "car psi: ";
            std::cout << Honda.psi * 180 / PI;
            std::cout << "\n";
            std::cout << "index: ";
            std::cout << index;
            std::cout << "\n";
            std::cout << "WheelAngCmd: ";
            std::cout << Honda.WheelAngCmd * 180 / PI;
            std::cout << "\n";
            //Road.printPath();
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
