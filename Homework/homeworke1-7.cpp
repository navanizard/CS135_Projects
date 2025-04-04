/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: January 30, 2025
Assignment: Homework E1.7

This program prints 3 user-inputted names on seperate lines.
*/


#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Enter 3 names: " << endl;

    cout << "Name 1: ";
    string name1;
    cin >> name1;

    cout << endl << "Name 2: ";
    string name2;
    cin >> name2;

    cout << endl << "Name 3: ";
    string name3;
    cin >> name3;

    cout << endl << name1 << endl << name2 << endl << name3 << endl;

    return 0;
}