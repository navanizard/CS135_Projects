/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 25, 2025.
Assignment: Lab4D

This program prints prints the bottom-left half 
of a square, given the side length.
*/

#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Input side length: ";
    cin >> size;
    cout << "Shape:" << endl;
    for (int col = 1; col <= size; col++){
        for (int row = 0; row < col; row++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}