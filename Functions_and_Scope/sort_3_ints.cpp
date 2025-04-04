/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 9, 2025
Assignment: Homework E5.15

This program defines a function sort3(int& a, int& b, int& c) that swaps its three
arguments to arrange them in sorted order.
*/

#include <iostream>
using namespace std;

void sort2(int& a, int& b);
void sort3(int& a, int& b, int& c);

int main(){
    int v = 3;
    int w = 4;
    int x = 1;
    sort3(v, w, x);
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
    //ALTERNATIVE: swap(a, b) found in <algoritm> library.
}

void sort3(int& a, int& b, int& c){
    sort2(a, b); //Compare a and b, swap if necessary --> Ensures a ≤ b
    sort2(b, c); //Compare b and c, swap if necessary --> Ensures b ≤ c
    sort2(a, b); //Compare a and b again, swap if necessary --> Ensures a ≤ b after previous swaps
}