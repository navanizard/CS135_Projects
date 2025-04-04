/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 4, 2025
Assignment: Lab2A

This program asks the user to input an integer in the range 0 < n < 100. 
If the number is out of range, it keeps asking to re-enter until a valid number is input.
After a valid value is obtained,  it print this number n squared
*/

#include <iostream>
using namespace std;

int main(){
    int num;

    cout << "Please enter an integer: ";
    cin >> num;

    while ((num <= 0) || (num >= 100)){
        cout << "Please re-enter: ";
        cin >> num;
    }

    cout << "Number squared is " << num*num;


    return 0;
}