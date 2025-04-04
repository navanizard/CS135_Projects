/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 25, 2025.
Assignment: Lab4B

This program prints a rectangular checkerboard of asterisks and spaces (alternating)
using user-inputted measurements (width and height).
*/

#include <iostream>
using namespace std;

int main(){
    int width, height;
    cout << "Input Width: "; //the amount of columns
    cin >> width;
    cout << "Input Height: "; //the amount of rows
    cin >> height;
    cout << "Shape: " << endl;

    for (int col = 0; col < height; col++){
        if (col % 2 == 0){
            for (int row = 0; row < width; row++){
                if (row % 2 == 0){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
            cout << endl;
        }
        else{
            for (int row = 0; row < width; row++){
                if (row % 2 == 0){
                    cout << " ";
                }
                else{
                    cout << "*";
                }
            }
            cout << endl;
        }

    }
    
    return 0;
}