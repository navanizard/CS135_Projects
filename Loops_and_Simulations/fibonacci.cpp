/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 9, 2025
Assignment: Lab2D

This program uses an array of ints to compute and 
print all Fibonacci numbers from F(0) to F(59).
*/

#include <iostream>
using namespace std;

int main(){
    //Create an array with a capacity of 60 elements.
    int fib[60];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 0; i < 60; i++){
        fib[i] = fib[i-1] + fib[i-2];
        cout << fib[i] << endl;
    }

    return 0;
}

/*
Towards the end of the computation, the outputs alternate (unorderedly) to negative values.
This happens because those integers exceed the capacity for the int data type.

EXPLANATION FROM BRIEF C++ SPECIAL TOPIC 2.2:
    "Because numbers are represented in the computer with a limited number of digits, they cannot 
    represent arbitrary integer or floating-point numbers. 
    The int type has a limited range: On most platforms, it can represent numbers up to a little 
    more than two billion. For many applications, this is not a problem, but you cannot use an int 
    to represent the world population. 
    If a computation yields a value that is outside the int range, the result overflows. No error 
    is displayed. Instead, the result is truncated to fit into an int, yielding a useless value."
*/