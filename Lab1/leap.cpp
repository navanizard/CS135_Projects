/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 3, 2025
Assignment: Lab1C

This program asks the user to input a year and outputs whether that year
is a leap or common year.
*/

#include <iostream>
using namespace std;

int main(){
    int year;
    cout << "Enter the year: ";
    cin >> year;
    if (year%4 != 0){
        cout << "Common Year";
    }
    else if (year%100 != 0){
        cout << "Leap Year";
    }
    else if (year%400 != 0){
        cout << "Common Year";
    }
    else{
        cout << "Leap Year";
    }


    return 0;
}