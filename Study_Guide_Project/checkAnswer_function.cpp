/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 19, 2025.
Assignment: Project 2A

This program organizes Project1 into functions, as oppose to having all the code
in the main function. It defines a function that reads data from a file into
an array, and another function that displays all the contents of an array.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;

struct Question {
    string text, answer, explanation, version, label, type;
};

void read_file(string fileName, Question ques[], int capacity, int& size);
void display(Question ques[], int size);

int main(){
    const int CAPACITY = 1000;
    int size = 0;
    Question ques[CAPACITY];
    
    read_file("cs135_midterm_f24_v1.txt", ques, CAPACITY, size);
    read_file("cs135_midterm_f24_v2.txt", ques, CAPACITY, size);
    read_file("cs135_midterm_s24_v1.txt", ques, CAPACITY, size);

    display(ques, size);

    return 0;
}

void read_file(string fileName, Question ques[], int capacity, int& size){
    //test the file if it can be opened.
    ifstream fin(fileName);
    if(fin.fail()){
        cerr << "File could not be opened. ";
        exit(1);
    }

    string line, text, answer, explanation, version, label, type;

    //Read the data line by line
    while(getline(fin, line) && !line.starts_with("question: ")) //Read the data until it starts with "question:"
        ; 

    while(line.starts_with("question: ")){
            text = line.substr(strlen("question: ")); //remove the text "question: " to only get the contents.
            while(getline(fin, line) && !line.starts_with("answer: ")){
                text+= '\n' + line;
            }

        if(line.starts_with("answer: ")){
            answer = line.substr(strlen("answer: "));
            while(getline(fin, line) &&   !(line.starts_with("explanation: ") || 
                                            line.starts_with("type: ") || 
                                            line.starts_with("version: ") || 
                                            line.starts_with("label: ") || 
                                            line.starts_with("question: "))){
                answer+= '\n' + line;
            } 
        }

        if(line.starts_with("explanation: ")){
            explanation = line.substr(strlen("explanation: "));
            while(getline(fin, line) &&   !(line.starts_with("version: ") || 
                                            line.starts_with("label: ") || 
                                            line.starts_with("type: ") ||
                                            line.starts_with("question: "))){
                explanation+= '\n' + line;
            }
        }

        do{
            if(line.starts_with("version: ")){ 
                version = line.substr(strlen("version: "));
            }

            if(line.starts_with("label: ")){ 
                label = line.substr(strlen("label: "));
            }

            if(line.starts_with("type: ")){ 
                type = line.substr(strlen("type: "));
            }

        } while(getline(fin, line) && !line.starts_with("question: "));

        //if there's no sufficient capacity, quit the program.
        if (size >= capacity){
            return; 
        }
        //Store all the data collected into the array, after a full question is read.
        ques[size].text = text;
        ques[size].answer = answer;
        ques[size].explanation = explanation;
        ques[size].version = version;
        ques[size].label = label;
        ques[size].type = type;
        size++;
        //Reset variables for a new question
        text = answer = explanation = version = label = type = ""; 
    }
    fin.close();
}

void display(Question ques[], int size){
    for(int i = 0; i < size; i++){
        cout << i + 1 << endl;
        cout << "Question: " << ques[i].text << endl; 
        cout << "Answer: " << ques[i].answer << endl;
        cout << "Explanation: " << ques[i].explanation << endl;
        cout << "Version: " << ques[i].version << endl;
        cout << "Label: " << ques[i].label << endl;
        cout << "Type: " << ques[i].type << endl;
        cout << endl;
    }
}
