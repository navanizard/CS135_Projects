/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 23, 2025
Assignment: Lab12B

This program implements a function that, given a vector of integers, 
returns a vector with only the positive integers in the same order.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(const vector<int> v);

int main(){
    vector<int> v{1,2,-1,3,4,-1,6};
    int len = v.size();
    vector<int> n = goodVibes(v); // returns [1,2,3,4,6]
    for (int i = 0; i < len; i++){
        cout << n[i] << endl;
    }


    return 0;
}

vector<int> goodVibes(const vector<int> v)
{
    int len = v.size();
    vector<int> v2;
    for (int i = 0; i < len; i++){
        if(v[i] > 0){
            v2.push_back(v[i]);
        }
    }
    return v2;
}

