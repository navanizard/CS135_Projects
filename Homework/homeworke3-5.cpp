/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: January 30, 2025
Assignment: Homework E3.5

This program reads three numbers and prints “increasing” if they are in 
increasing order, “decreasing” if they are in decreasing order, and “neither” other
wise.
*/

#include <iostream>
using namespace std;

int main() {
    int num1;
    int num2;
    int num3;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the third number: ";
    cin >> num3;

//If num1 is the smallest --> and num2 is smaller than num3 = increasing.
    if ((num1 < num2) && (num1 < num3)){
        if (num2 < num3){
            cout << "Increasing";
        }
         else{
            cout << "Neither.";
        }
    }
//If num1 is the biggest --> and num2 is bigger than num3 = decreasing.
    else if ((num1 > num2) && (num1 > num3)){
        if (num2 > num3){
            cout << "Decreasing.";
        }
        else{
            cout << "Neither.";
        }
    }

//All other possibilities = neither
    else{
        cout << "Neither.";
    }

    return 0;
}