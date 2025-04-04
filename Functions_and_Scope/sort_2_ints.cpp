/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 9, 2025
Assignment: Homework E5.14

This program defines a function sort2(int& a,int& b) that swaps the values of a and b if
a is greater than b and otherwise leaves a and b unchanged
*/

#include <iostream>
using namespace std;

void sort2(int& a, int& b);

int main(){
    int u = 2;
    int v = 3;
    int w = 4;
    int x = 1;
    sort2(u, v);
    sort2(w, x);
    cout << "u: " << u << endl; //the argument for a reference parameter must be a variable.
    cout << "v: " << v << endl;
    cout << "w: " << w << endl;
    cout << "x: " << x << endl;
    return 0;
}

void sort2(int& a, int& b){
    if (a > b){
        int temp_a = a;
        a = b;
        b = temp_a;
    }
}

