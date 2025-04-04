/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 27, 2025
Assignment: Homework E7.18

This program defines a structure Triangle that contains three Point members,
and defines a function that computes the perimeter of a Triangle.
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

class Triangle {
    public:
    Triangle();
    Triangle(Point t1, Point t2, Point t3);
    void print();
    Point get_p1();
    Point get_p2();
    Point get_p3();

    private:
        Point a;
        Point b;
        Point c;
};

double distance(Point a, Point b);
double perimeter(Triangle t);

int main(){
    Point p1(0,0);
    Point p2(4,0);
    Point p3(0,3);

    Triangle t1(p1, p2, p3);
    t1.print();
    cout << "Perimeter of the triangle is: " << perimeter(t1) << endl;
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


Triangle::Triangle(Point t1, Point t2, Point t3){
    a = t1;
    b = t2;
    c = t3;
}

void Triangle::print(){
    cout << "Triangle: " << endl;
    cout << "P1: "; 
    a.print();
    cout << "P2: "; 
    b.print();
    cout << "P3: "; 
    c.print();
}

Point Triangle::get_p1(){
    return a;
}

Point Triangle::get_p2(){
    return b;
}

Point Triangle::get_p3(){
    return c;
}

double perimeter(Triangle t){
    Point p1 = t.get_p1();
    Point p2 = t.get_p2();
    Point p3 = t.get_p3();
    double d1 = distance(p1, p2);
    double d2 = distance(p1, p3);
    double d3 = distance(p2, p3);
    return d1 + d2 + d3;
}