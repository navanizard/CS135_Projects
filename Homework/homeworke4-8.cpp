/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 9, 2025
Assignment: Homework E4.8

This program reads a word and prints each character of the word on a separate
line. For example, if the user provides the input "Harry", the program prints
H
a
r
r
y
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string word;
    cout << "Enter a word: ";
    cin >> word;

    for (int i = 0; i < word.length(); i++){
        cout << word.substr(i, 1) << endl;
    }

    return 0;
}