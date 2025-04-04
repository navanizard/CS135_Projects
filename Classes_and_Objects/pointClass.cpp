/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 27, 2025
Assignment: Homework E7.16

This program defines a structure Point with an x and y 
coordinate, and defines a function of that class that calculates
the distance between two points using the distance formula.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Point {
    public:
        Point();
        Point(double x_value, double y_value);
        void print(); //print out the coordinate for testing.
        double get_x_value();
        double get_y_value();

    private:
        double x; //x-coordinate
        double y; //y-coordinate
};
double distance(Point a, Point b);

int main(){
    Point p1;
    // p1.print();
    Point p2(4, 6);
    // p2.print();
    // cout << p2.get_x_value();
    cout << distance(p1, p2); //Should be 7.2
    return 0;
}

Point::Point(){
    x = y = 0;
}

Point::Point(double x_value, double y_value){
    x = x_value;
    y = y_value;
}

void Point::print(){
    cout << "(" << x << ", " << y << ")" << endl;
}

double Point::get_x_value(){
    return x;
}

double Point::get_y_value(){
    return y;
}

double distance(Point a, Point b){
    double x1 = a.get_x_value();
    double x2 = b.get_x_value();
    double y1 = a.get_y_value();
    double y2 = b.get_y_value();
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)); //distance formula
}