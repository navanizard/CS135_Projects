/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 13, 2025
Assignment: Lab3B

This program reads data from a TSV file using the fstream library, and prints
the maximum and minimum occuring values in East Basin in 2018.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits> //INT_MAX, INT_MIN
using namespace std;

int main(){
    string date;
    double eastSt;
    double max_value = INT_MIN;
    double min_value = INT_MAX;
    
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        cerr << "File cannot be opened.";
        exit(1);
    }

    string junk;
    getline(fin, junk);

    while (fin >> date >> eastSt){
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignorring the remaining columns 
        if (eastSt > max_value){
            max_value = eastSt;
        }
        if (eastSt < min_value){
            min_value = eastSt;
        }
    }
    fin.close();

    cout << "Minimum storage in east basin: " << min_value << " billion gallons." << endl;
    cout << "Maximum storage in east basin: " << max_value << " billion gallons." << endl;

    return 0;
}