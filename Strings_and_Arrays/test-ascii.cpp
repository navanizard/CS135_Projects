/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 4, 2025.
Assignment: Lab6A

This program prints a user inputted string character by character with the ASCII
value of each character.
*/

#include <iostream>
#include <string>
#include <cctype> //useful functions for char
using namespace std;

int main(){
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    int len = text.length();
    for(int idx = 0; idx < len; idx++){
        cout << text[idx] << ' ' << (int)text[idx] << endl; //type cast the char into an int
    }
    
    return 0;
}

