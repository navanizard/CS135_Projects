/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 16, 2025
Assignment: Homework E6.1

This program initializes n array with ten random integers and then prints 
four lines of output, containing:
• Every element at an even index.
• Every even element.
• All elements in reverse order.
• Only the first and last element
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int const SIZE = 10;
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand();
        // cout << arr[i] << endl;
    }

    //every element at an even index
    for (int i = 0; i < SIZE; i++){
        if (i % 2 == 0){
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    //every even element
    for (int i = 0; i < SIZE; i++){
        if (arr[i] % 2 == 0){
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    //all elements in reverse order
    for (int i = SIZE - 1; i > -1; i--){
        cout << arr[i] << " ";
    }
    cout << endl;

    //only the first and last element
    for(int i = 0; i < SIZE; i++){
        if (i == 0 || i == SIZE - 1){
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

