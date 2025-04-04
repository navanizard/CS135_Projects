/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 4, 2025
Assignment: Lab2B

This program sks the user to input two integers L and U (representing the lower 
and upper limits of the interval), and print out all integers in the range 
L ≤ i < U separated by spaces  (including the lower limit, but excluding the upper limit).
*/

#include <iostream>
using namespace std;

int main(){
    int numL;
    int numU;

    cout << "Please enter L: ";
    cin >> numL;

    cout << "Please enter U: ";
    cin >> numU;

    for (int i = numL; i < numU; i++){
        cout << i << " ";
    }


    return 0;
}