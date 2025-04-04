/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 4, 2025.
Assignment: Project 1A

This program displays 2 questions and asks the user to answer them. 
If the answer is correct, we display true, otherwise, we display false.
*/


#include <iostream>
#include <string>
using namespace std;

int main(){
    //Declare all variables.
    string questionTxt1;
    string expAnswer1;
    string userA1;

    string questionTxt2;
    string expAnswer2;
    string userA2;

    bool result1;
    bool result2;
    
    //Initialize the variables with their values.
    questionTxt1 = "What is -1 + 5 / 3 ? ";
    expAnswer1 = "0";

    questionTxt2 = "Assume that n is properly declared and initialized. Write a condition to represent that n does NOT satisify 0 < n < 100. ";
    expAnswer2 = "(n <= 0 || n >= 100)";

    //Display the question, and receive input.
    cout << questionTxt1;

    /*
    The < getline(cin, stringVariable); > function takes a whole line from console and 
    put the value to stringVariable. 
    The first parameter of getline is either the Standard input stream object like 
    cin or an ifstream object, which reads input from a file. The 
    second parameter must be a string variable. That is, getline can only save the input 
    to a string.
    */
    getline(cin, userA1);
    cout << "Your Answer: " << userA1;

    if (userA1 == expAnswer1){
        result1 = 1;
    }
    else{
        result1 = 0;
    }

    //boolalpha print out "true" or "false" instead of "1" and "0"
    cout << endl << boolalpha << result1 << endl;

    cout << questionTxt2;

    getline(cin, userA2);

    cout << "Your Answer: " << userA2;

    if (userA2 == expAnswer2){
        result2 = 1;
    }
    else{
        result2 = 0;
    }

    cout << endl << boolalpha << result2;



    return 0;
}
