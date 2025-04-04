/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 9, 2025
Assignment: Homework E8.1

This program opens a the file "hello.txt", writes "Hello, World!" in it,
then reads the file and prints its contents.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream fout("hello.txt"); //open a file with the name hello.txt
    if (fout.fail()){ //check if file can't be opened.
        cerr << "File cannot be opened. ";
        exit(1);
    }
    fout << "Hello, World!"; //store the message "Hello, World!" in the file.
    fout.close(); // close the file

    fstream fin("hello.txt"); //open the same file again.
    if (fin.fail()){ //check if file can't be opened.
        cerr << "File cannot be opened. ";
        exit(1);
    }
    string line;
    getline(fin, line); //read the message into a string variable
    fin.close();
    cout << line; //print it

    return 0;
}