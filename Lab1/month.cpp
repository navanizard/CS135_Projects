/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 3, 2025
Assignment: Lab1D

This program asks the user to input a year and month, and will print out
the amount of days.
*/

#include <iostream>
using namespace std;

//Leap Year Function
bool isLeap(int year) {
    if (year%4 != 0){
        return false;
    }
    else if (year%100 != 0){
        return true;
    }
    else if (year%400 != 0){
        return false;
    }
    return true;
}
//Main Function
int main(){
    int year;
    int month;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the month: ";
    cin >> month;
    bool isLeapYear = isLeap(year);

    if ((month >= 1) && (month <= 7)){
        if (month == 2){
            if (isLeapYear == true){
                cout << "29 days";
            }
            else{
                cout << "28 days";
            }
        }
        else if (month % 2 == 0){
            cout << "30 days";
        }
        else{
            cout << "31 days";
        }
    }

    if ((month > 7) && (month <= 12)){
        if (month % 2 == 0){
            cout << "31 days";
        }
        else{
            cout << "30 days";
        }
    }

    return 0;
}

/*
Alternate: Write out 12 if statements (one for each month)
*/