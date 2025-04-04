/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: January 30, 2025
Assignment: Lab1B

This program asks the user to input three integer, and prints out the smallest of the three.
*/

#include <iostream>
using namespace std;

int main() {
    int num1;
    int num2;
    int num3;

    cout << "Enter the first integer: ";
    cin >> num1;

    cout << "Enter the second integer: ";
    cin >> num2;

    cout << "Enter the third integer: ";
    cin >> num3;

//Get the smallest of num1 and num2 and then compare it to num3

    if (num1 < num2){
        if (num1 < num3){
            cout << "The smallest number is: " << num1;
        }
        else if (num1 > num3){
            cout << "The smallest number is: " << num3;
        }
    }

    else if (num2 < num1){
        if (num2 < num3){
            cout << "The smallest number is: " << num2;
        }
        else if (num2 > num3){
            cout << "The smallest number is: " << num3;
        }
    }

    return 0;
}