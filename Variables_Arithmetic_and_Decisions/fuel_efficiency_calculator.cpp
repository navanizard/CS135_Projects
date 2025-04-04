/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: January 30, 2025
Assignment: Homework E2.10

This program asks the user to input
 • The number of gallons of gas in the tank
 • The fuel efficiency in miles per gallon
 • The price of gas per gallon

 Then print the cost per 100 miles and how far the car can go with the gas in the tank
*/

#include <iostream>
using namespace std;

int main() {
    int galInTank;
    int fuelMPG;
    float pricePG;
    int miles;
    float total;

    cout << "Enter the number of gallons of gas in the tank: ";
    cin >> galInTank;

    cout << "Enter the fuel efficiency in miles per gallon: ";
    cin >> fuelMPG;

    cout << "Enter the price of gas per gallon: ";
    cin >> pricePG;

//Calculations:
    miles = fuelMPG * galInTank;
    total = (100.0 /fuelMPG) * pricePG;

//Output:
    cout << "This car can go " << miles << " miles with the gas in the tank." << endl;
    cout << "The cost per 100 miles is " << total << " dollars.";

    return 0;
}