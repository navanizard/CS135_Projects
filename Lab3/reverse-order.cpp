/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 15, 2025
Assignment: Lab3D

This program reads data from a TSV file using the fstream library, and asks the user to input 
two dates (earlier date then later date). The program then reports the West basin elevation 
for all days in the interval in the reverse chronological order (from the later date to the earlier).
*/

#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include <cstdlib>
using namespace std;

int main() {
    //variables for the data stored in the file.
    string date; 
    double eastEl;
    double eastSt;
    double westEl;
    double westSt;
    //other variables
    string start_date; //user start date
    string end_date; //user end date
    const int CAPACITY = 366;
    string arr_date_range[CAPACITY];
    double arr_west_el[CAPACITY];
    int count = 0; //keep track of elements in the array

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        cerr << "File cannot be opened.";
        exit(1);
    }

    string header; //skip the header in the file
    getline(fin, header);

    //Get the user to enter date range
    cout << "Enter earlier date: ";
    cin >> start_date;
    cout << "Enter later date: ";
    cin >> end_date;

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl){
        if ((date <= end_date) && (date >= start_date)){ //if the data date is within the user range
            arr_date_range[count] = date; //then store that date into the array
            arr_west_el[count] = westEl; //store the elevation for that date into west_arr.
            count++;
        }
    }

    //Loop through all the dates and elevation values in reverser order
    for(int i = count - 1; i >= 0; i--){
        cout << arr_date_range[i] << " " << arr_west_el[i] << " ft" << endl;
    }

    fin.close();

    return 0;

}