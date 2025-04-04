/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 10, 2025
Assignment: Homework E5.6

This program creates a function middle(str) that takes in a string and returns the middle char.
*/

/** 
FUNCTION COMMENTS:
    Returns a string containing the middle character in str if the length of str is odd, 
    or the two middle characters if the length is even  
    @param str the string entered by the user
    @return the middle (or middle 2) characters of the string entered
*/

#include <iostream>
#include <string>
using namespace std;

string middle(string str){
    int length_of_string = str.length();
    int last_index = length_of_string - 1;
    int middle_index; //the first one that occurs in the case that it's even
    string middle_char;
    string new_str;

    //If its odd
    if (length_of_string % 2 != 0){
        middle_index = last_index / 2;
        new_str = str.substr(middle_index, 1);
        return new_str;
    }
    else{
        middle_index = (length_of_string / 2) - 1;
        new_str = str.substr(middle_index, 2);
        return new_str;
    }

    return 0;
}

//Unit tests to check that function works as expected. 
int main(){
    cout << middle("middle") << endl;
    cout << "Expected \"dd\"." << endl;
    cout << middle("hello") << endl;
    cout << "Expected \"l\"." << endl;
    return 0;
}