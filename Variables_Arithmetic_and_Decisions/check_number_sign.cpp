/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: January 30, 2025
Assignment: Homework E3.1

This program asks the user to input an integer and prints out whether it's positive, negative, 
or zero.
*/

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num > 0){
        cout << num << " is a positive integer. ";
    }
    else if (num < 0){
        cout << num << " is a negative integer. ";
    }
    else{
        cout << "You entered zero.";
    }

    return 0;
}