/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 2, 2025
Assignment: Lab9 (Tasks A-C, E)

This program defines functions:
- length() that receives the coordinates of a point P passed as a pointer, 
    and computes the distance from the origin to the point P.
- fatherFromOrigin() which receives the coordinates of two points (passed as pointers), 
    and returns the pointer of the point that is farther away from the origin.
- move() which gets the position and the velocity of an object and has to compute object’s 
    new coordinates after the time interval dt. The function does not return any values, 
    instead, it should update the object’s position ppos with its new position coordinates.
- createCoord3D() which creates a dynamically allocated pointer to Coord3D object.
- deleteCoord3D() which releases the memory back to the system after usage.
*/


#include <iostream>
#include <cmath>
using namespace std;

class Coord3D 
{
    public:
        double x, y, z; //Public data members
        Coord3D(); //Default constructor
        Coord3D(double x_value, double y_value, double z_value); //Parametized constructor   
};

double length(Coord3D *p);
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
void move(Coord3D *ppos, Coord3D *pvel, double dt);
Coord3D* createCoord3D(double x, double y, double z);
void deleteCoord3D(Coord3D *p);

int main()
{
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);

    //EXPECTED OUTPUT:
    // Enter position: 10 20 30
    // Enter velocity: 5.5 -1.4 7.77
    // Coordinates after 10 seconds: 65 6 107.7
    return 0;
}

Coord3D::Coord3D()
{
    x = y = z = 0;
}

Coord3D::Coord3D(double x_value, double y_value, double z_value)
{
    x = x_value;
    y = y_value;
    z = z_value;
}

double length(Coord3D *p)
{
    // p is the adress of a coord3d object. a pointer to a coord3d object.
    //since the data members are public and this function is not part of the 
        //coord3d class, can access them directly.
    return sqrt((p->x * p->x) + (p->y * p->y) + (p->z * p->z));
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
    double distance_a = length(p1);
    double distance_b = length(p2);
    if (distance_a > distance_b){
        return p1;
    }
    else
        return p2;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
    ppos->x += pvel->x * dt;
    ppos->y += pvel->y * dt;
    ppos->z += pvel->z * dt;
}

Coord3D* createCoord3D(double x, double y, double z)
{
    Coord3D *p = new Coord3D;
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}

void deleteCoord3D(Coord3D *p)
{
    delete p;
    p = nullptr;
}

