/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 3, 2025
Assignment: Homework E9.5

This program implements a class Rectangle, and provides a constructor to construct a 
rectangle with a given width and height. It also defines member functions get_perimeter() 
and get_area() that compute the perimeter and area, as well as a member function
void resize(double factor) that resizes the rectangle by multipying the width and height by 
the given factor.
*/

#include <iostream>
using namespace std;

class Rectangle 
{
    public: 
        Rectangle(double width, double height); //parametized constructor
        double get_perimeter() const; //accessor member function
        double get_area() const; //accessor member function
        void resize(double factor);
    private:
        double width, height; //private data members
};

int main()
{
    Rectangle r(2, 4);
    cout << "Perimeter: " << r.get_perimeter() << endl; //expected 12
    cout << "Area: " << r.get_area() << endl; //expected 8
    r.resize(4);
    cout << "Perimeter: " << r.get_perimeter() << endl; //expected 48
    cout << "Area: " << r.get_area() << endl; //expected 128
    return 0;
}

Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
}

double Rectangle::get_perimeter() const
{
    return 2*width + 2*height;
}

double Rectangle::get_area() const
{
    return width * height;
}

void Rectangle::resize(double factor)
{
    width *= factor;
    height *= factor;
}