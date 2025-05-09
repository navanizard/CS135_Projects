/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 28, 2025
Assignment: Homework E6.18

This program implements a function that returns a vector composed of all
the elements in the first and all the elements in the second vector
passed as arguments.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b);

int main(){
    vector<int> v1{3, 4, 56, 8};
    vector<int> v2{2, 45, 12, 67};
    vector<int> v3 = append(v1, v2);
    for (int i = 0; i < v3.size(); i++){
        cout << v3[i] << " ";
    }

    return 0;
}

vector<int> append(vector<int> a, vector<int> b){
    vector<int> c;
    for(int i = 0; i < a.size(); i++){
        c.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++){
        c.push_back(b[i]);
    }
    return c;
}