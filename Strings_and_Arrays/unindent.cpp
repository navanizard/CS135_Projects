/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 13, 2025.
Assignment: Lab7A

This program defines a function that unindents strings (removes the leading
white spaces). 
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string string);

int main(){
    string string;
    // cout << "Enter a string: ";
    while(getline(cin, string)){
        cout << removeLeadingSpaces(string) << endl;
    }
    // string string = "       int x = 1;  ";
    return 0;
}

string removeLeadingSpaces(string string){
    int len = string.length();
    int startIdx = 0;
    
    //find the first non-white space char:
    while(startIdx < len && isspace(string[startIdx])){
        startIdx++; //skip if the character is a space
    }
    
    return string.substr(startIdx);

}
