/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 2, 2025
Assignment: Lab9F

This program declares a new class Particle, which stores position and velocity of the particle, and
provides the following programming interface:
- dynamically allocates memory for a particle and initializes it
- sets its velocity to (vx, vy, vz)
- gets its current position
- updates particle's position after elapsed time dt
- deletes all memory allocated for the particle passed by pointer
*/

#include <iostream>
using namespace std;

class Coord3D 
{
    public:
        double x, y, z; //Public data members
        Coord3D(); //Default constructor
        Coord3D(double x_value, double y_value, double z_value); //Parametized constructor   
};

class Particle {
    public: 
    double x, y, z, vx, vy, vz;
};

Particle* createParticle(double x, double y, double z,
    double vx, double vy, double vz);
void setVelocity(Particle *p, double vx, double vy, double vz);
Coord3D getPosition(Particle *p);
void move(Particle *p, double dt);
void deleteParticle(Particle *p);

int main()
{
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);

    //EXPECTED OUTPUT:
    // Time: 0.1 	Position: 1, 1.53, 2.01
    // Time: 0.2 	Position: 1.1, 1.56, 2.02
    // Time: 0.3 	Position: 1.3, 1.59, 2.03
    // Time: 0.4 	Position: 1.6, 1.62, 2.04
    // Time: 0.5 	Position: 2, 1.65, 2.05
    // Time: 0.6 	Position: 2.5, 1.68, 2.06
    // Time: 0.7 	Position: 3.1, 1.71, 2.07
    // Time: 0.8 	Position: 3.8, 1.74, 2.08
    // Time: 0.9 	Position: 4.6, 1.77, 2.09
    // Time: 1 	    Position: 5.5, 1.8, 2.1
    // Time: 1.1 	Position: 6.5, 1.83, 2.11
    // Time: 1.2 	Position: 7.6, 1.86, 2.12
    // Time: 1.3 	Position: 8.8, 1.89, 2.13
    // Time: 1.4 	Position: 10.1, 1.92, 2.14
    // Time: 1.5 	Position: 11.5, 1.95, 2.15
    // Time: 1.6 	Position: 13, 1.98, 2.16
    // Time: 1.7 	Position: 14.6, 2.01, 2.17
    // Time: 1.8 	Position: 16.3, 2.04, 2.18
    // Time: 1.9 	Position: 18.1, 2.07, 2.19
    // Time: 2 	    Position: 20, 2.1, 2.2
    // Time: 2.1 	Position: 22, 2.13, 2.21
    // Time: 2.2 	Position: 24.1, 2.16, 2.22
    // Time: 2.3 	Position: 26.3, 2.19, 2.23
    // Time: 2.4 	Position: 28.6, 2.22, 2.24
    // Time: 2.5 	Position: 31, 2.25, 2.25
    // Time: 2.6 	Position: 33.5, 2.28, 2.26
    // Time: 2.7 	Position: 36.1, 2.31, 2.27
    // Time: 2.8 	Position: 38.8, 2.34, 2.28
    // Time: 2.9 	Position: 41.6, 2.37, 2.29
    // Time: 3 	    Position: 44.5, 2.4, 2.3
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

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z,
                        double vx, double vy, double vz)
{
    Particle* p = new Particle;
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    return p;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz)
{
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}

// get its current position
Coord3D getPosition(Particle *p)
{
    Coord3D point;
    point.x = p->x;
    point.y = p->y;
    point.z = p->z;
    return point;
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt)
{
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p)
{
    delete p;
    p = nullptr;
}