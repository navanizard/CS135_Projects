/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 26, 2025.
Assignment: Lab4G

This program prints prints a checkerboard of 3-by-3 squares
of the dimensions of the user-inputted width and height.
*/

#include <iostream>
using namespace std;

int main(){
    int width, height;
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;
    cout << "Shape:" << endl;

    
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            if ((row / 3 + col / 3) % 2 == 0){
                cout << '*';
            }
            else{
                cout << ' ';
            }
        }
        cout << endl;  
    }
    return 0;
}

//Explanation:

// Dividing by 3 → Groups rows and columns into blocks of 3 (since each square is 3x3).
// Example:
// Rows 0,1,2 → Group 0
// Rows 3,4,5 → Group 1
// Rows 6,7,8 → Group 2
// (Same logic for columns)

// Adding row / 3 + col / 3 → Identifies which block we're in.
// If both are from the same type of block, their sum is even → Print *.
// If one is from an odd group, the sum is odd → Print space.

