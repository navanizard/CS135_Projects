/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 19, 2025
Assignment: Homework E7.1

This program defines a function sort2 that receives two pointers and sorts 
the values to which they point, such that x <= y.
*/

#include <iostream>
using namespace std;

void sort2(double* p, double* q); 

int main(){
    double x, y;
    x = 842.532;
    y = 12.34245;
    cout <<"OG x: " << x << endl;
    cout <<"OG y: " << y << endl;
    sort2(&x, &y);
    cout << "Sorted x: " << x << endl;
    cout << "Sorted y: " << y << endl;

    return 0;
}

//decreasing order
void sort2(double* p, double* q){
    if (*p > *q){
        double temp = *q;
        *q = *p;
        *p = temp;
        //ALTERNATIVE: swap(*p, *q) in <algorithm> library.
    }
}

//NOTES ON POINTERS:
// A pointer denotes the location of a variable in memory.
// The & operator  yields the location  of a variable
// The * operator accesses the variable to which a pointer points. 
