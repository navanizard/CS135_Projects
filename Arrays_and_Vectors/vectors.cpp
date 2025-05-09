/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 23, 2025
Assignment: Lab12A

This program defines a function that creates an integer
vector with a user specified size.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> makeVector(int n); //returns a vector of n integers from [0, n-1]

int main(){
    vector<int> go = makeVector(8);
    for (int i = 0; i < 10; i++){
        cout << go[i] << endl;
    }
    return 0;
}

vector<int> makeVector(int n)
{
    vector<int> v; //creates an integer vector object called v
    for (int i = 0; i < n; i++){
        v.push_back(i);
    }
    return v;
}