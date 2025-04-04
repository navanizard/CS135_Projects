/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 16, 2025
Assignment: Homework E6.8

This program defines a function to checks whether two arrays 
have the same elements in the same order.
*/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size);

int main(){
    int a1[10];
    int a2[5] = {5, 2, 1, 5, 3};
    int a3[10];
    for (int i = 0; i < 10; i++){
        a1[i] = i;
        a3[i] = i;
    }

    cout << equals(a1, 10, a2, 5) << endl;
    cout << equals(a1, 10, a3, 10) << endl;
    cout << equals(a2, 5, a3, 10) << endl;

    return 0;
}

bool equals(int a[], int a_size, int b[], int b_size){
    if(a_size != b_size){
        return 0;
    }
    for(int i = 0; i < a_size; i++){
        if (a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}
