/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: January 30, 2025
Assignment: Lab1A

This program asks the user to input two integers and prints out the smaller of the two.
*/

#include <iostream>
using namespace std;

int main() {
    int num1;
    int num2;

    cout << "Enter two integers:" << endl;

    cout << "Integer 1: ";
    cin >> num1;

    cout << "Integer 2: ";
    cin >> num2;

    cout << "The smaller of the two integers entered is: ";


    if (num1 > num2) {
        cout << num2;
    }

    else if (num1 < num2){
        cout << num1;
    }

    else{
        cout << "There was an error with your submission.";
    }

    return 0;
}