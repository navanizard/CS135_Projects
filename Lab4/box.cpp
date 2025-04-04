/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 18, 2025.
Assignment: Lab4A

This program print a rectangle of asterix using user-inputted measurements (width and height).
*/

#include <iostream>
using namespace std;

int main(){
    int width, height;

    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;

    cout << "Shape:" << endl;
    for (int h = 0; h < height; h++){
        for (int w = 0; w < width; w++){
            cout << "*";
        }
        cout << endl;  
    }

    return 0;
}