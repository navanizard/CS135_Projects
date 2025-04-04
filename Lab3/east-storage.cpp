/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 13, 2025
Assignment: Lab3A

This program reads data from a TSV file using the fstream library. It collects user input of a date, and
print out the east storage data from that date.
*/

//Include all necessary headers.
#include <iostream>
#include <string>
#include <fstream> //ifstream and ofstream (input and output stream)
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
    string date;
    string user_date;
    double eastSt;


    ifstream fin("Current_Reservoir_Levels.tsv"); //Read the input data from the file
    if (fin.fail()){ //Check if file can be opened.
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    
    //Read the first line of the TSV file - the header. 
    string junk;
    getline(fin, junk); 

    cout << "Enter date: ";
    getline(cin, user_date);

    while(fin >> date >> eastSt) { 
        // this loop reads the file line-by-line
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignorring the remaining columns 
        if (date == user_date){
            cout << "East basin storage: " << eastSt << " billion gallons.";
        }
    }
    
    fin.close(); //Once you're done reading the file, close the stream.

    return 0;
}