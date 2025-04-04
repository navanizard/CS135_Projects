/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 9, 2025.
Assignment: Lab2C

This program creates an array of 10 integers, 
and provides the user with an interface to edit any of its elements.
*/

#include <iostream>
using namespace std;

int main(){
    int myData[10];
    int i;
    int v;

    //Set all items in the array equal to 1.
    for (int i = 0; i < 10; i++){
        myData[i] = 1;
    }


    do {
        //Print all elements in the array
        for (int i = 0; i < 10; i++){
            cout << myData[i] << " ";
        }
    
        cout << endl << "Input Index: ";
        cin >> i;
        cout << "Input Value: ";
        cin >> v;
        
        if ((i >= 0) && (i <10)){
            //Update the array at index i to v.
            myData[i] = v;
        }
        else {
            cout << "Index out of range. Exit.";
            return 1;
        }
        

    } while ((i >= 0) && (i <10));
    


    return 0;
}