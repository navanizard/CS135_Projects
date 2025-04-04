/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 13, 2025
Assignment: Lab3C

This program reads data from a TSV file using the fstream library, and collects a range
of dates from the user. Then, for each day in that range, it prints which basin had
higher elevation that day - east, west, or equal values.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <climits> //INT_MAX, INT_MIN
using namespace std;

int main(){
    const int CAPACITY = 366;
    // string arr_date_range[CAPACITY]; //create an array to hold the date range the user will enter.
    string date;
    string start_date;
    string end_date;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    int count = 0; // elements in the array 
    bool inRange = false;


    ifstream fin("Current_Reservoir_Levels.tsv"); //collect and read the data from the file.
    if (fin.fail()){
        cerr << "File cannot be opened.";
        exit(1);
    }

    string junk;
    getline(fin, junk); //skip the header of the TSV file. once it reads it, doesnt go back. gets "rid of it"

    cout << "Enter starting date: "; //get user values for the date range
    getline(cin, start_date);
    cout << "Enter ending date: ";
    getline(cin, end_date);

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){ //loop through all the data in the file
        if (date == start_date){
            inRange = true;
        }

        if(inRange){
            if (eastEl > westEl){
                cout << date << " " << "East" << endl;
            } else if (eastEl < westEl){
                cout << date << " " << "West" << endl;
            } else if (eastEl == westEl){
                cout << date << " "<< "Equal" << endl;
            }
        }

        if (date == end_date){
            inRange = false;
        }

    }

        fin.close();
        return 0;
}





