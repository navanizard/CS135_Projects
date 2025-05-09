/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 23, 2025
Assignment: Lab12C

This program that implements a function that appends elements of the second vector into 
the first and empties the second vector.
*/

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta);


int main(){
    vector<int> a{2, 6};
    vector<int> b{1, 5, 23, 8, 34, 467};
    gogeta(a, b);
    return 0;
}

void gogeta(vector<int> &goku, vector<int> &vegeta)
{
    int len = vegeta.size();
    for (int i = 0; i < len; i++){
        goku.push_back(vegeta[i]);
    }
    vegeta.clear(); //empties vegeta of all its elements
}
