/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 26, 2025.
Assignment: Lab4F

This program prints prints an upside-down 
trapezoid of given width and height.
However, if the input height is impossibly large for the 
given width, then the program reports, "Impossible shape!"
*/

#include <iostream>
using namespace std;

int main(){
    int width, height;
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;

    int spaces = 0;
    int stars = width;

    if (width < (height * 2 - 1)){ //The condition for impossible shape.
        cout << "Impossible shape!";
    }

    else{
        cout << "Shape:" << endl;
        for (int col = 1; col <= height; col++){
            for (int sp = 0; sp < spaces; sp++){
                cout << ' ';
            }
            for(int st = 0; st < stars; st++){
                cout << '*';
            }
            spaces+= 1;
            stars-= 2;
            cout << endl;
        }
    }

    return 0;
}