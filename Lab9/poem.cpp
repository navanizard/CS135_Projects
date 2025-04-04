/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 2, 2025
Assignment: Lab9D

This program fixes the code by releasing the memory that was 
dynamically allocated after it is no longer needed.
*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point
        delete p;
        p = nullptr;
    }
}