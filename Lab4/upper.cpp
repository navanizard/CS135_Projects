/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 25, 2025.
Assignment: Lab4E

This program prints prints the top-right 
half of a square, given the side length.
*/

#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Input side length: ";
    cin >> size;
    cout << "Shape:" << endl;

    //Since row=1 !< col=1, print all stars
    //But, when row=2, by col=1, needs 1 space.
    //And when row=3, by col=1 and col=2, need spaces.
    for (int col = 1; col <= size; col++){
        for (int row = 1; row <= size; row++){
            if (row < col){ 
                cout << ' ';
            }
            else{
                cout << '*';
            }
        }
        cout << endl;
    }

    return 0;
}