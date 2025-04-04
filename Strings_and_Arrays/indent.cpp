/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 17, 2025.
Assignment: Lab7B

This program reads a C++ program, removes leading spaces, and adds proper indentation.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int countChar(string string, char c);
string removeLeadingSpaces(string string);


int main(){
    string line;
    //keep track of how many open blocks there are
    int openBlocks = 0;
    while(getline(cin, line)){
        line = removeLeadingSpaces(line);

        if(openBlocks < 0){ //prevent negative values
            openBlocks = 0;
        }

        //if the first character is a closing brace, decrease the indentation by one.
        if(line[0] == '}'){
            for (int i = 0; i < openBlocks - 1; i++){
                cout << '\t';
            }
        }
        else{
            for(int i = 0; i < openBlocks; i++){
                cout << '\t';
                
            }
        }          
        cout << line << endl;

        //adjust openBlocks for the next lines
        openBlocks+= countChar(line, '{');; // increase for the next lines. it opens a new block of code
        openBlocks-= countChar(line, '}');; // decrease. 
        

    }

    return 0;
}

// Function to count occurrences of character 'c' in a string
int countChar(string string, char c){
    int count = 0;
    int len = string.length();
    for (int i = 0; i < len; i++){
        if(string[i] == c){
            count++;
        }
    }
    return count;
}

// Function to remove leading spaces from a string
string removeLeadingSpaces(string string){
    int len = string.length();
    int startIdx = 0;
    
    //find the first non-white space char:
    while(startIdx < len && isspace(string[startIdx])){
        startIdx++;
    }
    
    return string.substr(startIdx);
}
