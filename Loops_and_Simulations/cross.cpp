/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 25, 2025.
Assignment: Lab4C

This program prints a diagonal cross of asterixs 
of the dimension of the user-inputted size.
*/

#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Input size: ";
    cin >> size;
    cout << "Shape:" << endl;

    int spaces = 0;

    for (int col = 0; col < size; col++){
        for (int row = 0; row < size; row++){
            if ((row == col || col + row == size - 1)){
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


//Forward diagonal:
// int size;
// cout << "Input size: ";
// cin >> size;
// cout << "Shape:" << endl;

// int spaces = 0;

// for (int col = 0; col < size; col++){
//     for (int row = 0; row <= spaces; row++){
//         if (row < col){
//             cout << ' ';
//         }
//         else{
//             cout << '*';  
//         }  
//     }
//     cout << endl;
//     spaces+=1;
// }