/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 5, 2025.
Assignment: Project 1D

This program extracts the types from a questions file, and asks the user
to complete a test based on the question type they choose. 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> //sort function
#include <string.h> //c-style strings
using namespace std;

bool exists(string arr[], int size, string element);
void append(string arr[], int& size, int capacity, string element);
void printArray(string arr[], int size);
string trim(string string);

struct Question {
    string text, answer, explanation, version, label, type;
};

int main(){
    int const CAPACITY = 250;
    Question questions[CAPACITY]; 
    string questionTypes[CAPACITY];
    string line; //To read the file line by line
    string text, answer, explanation, version, label, type;
    

    //Read the data from the file into fin:
    // string file = "cs135_midterm_f24_v2.txt";
    // string file = "civics_65_20.txt";
    string file;
    cout << "Enter file name: ";
    cin >> file;
    ifstream fin(file);
    if (fin.fail()){
        cerr << "File could not be opened.";
        exit(1);
    }

    //Read the data line by line
    int questionCount = 0;
    while(getline(fin, line) && !line.starts_with("question: ")) //Read the data until it starts with "question:".
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

        if(line.starts_with("version: ")){ 
            version = line.substr(strlen("version: "));
            while(getline(fin, line) &&   !(line.starts_with("label: ") || 
                                            line.starts_with("type: ") || 
                                            line.starts_with("question: "))){
                version+= '\n' + line;
            }
        }

        if(line.starts_with("label: ")){ 
            label = line.substr(strlen("label: "));
            while(getline(fin, line) && !(line.starts_with("type: ") ||
                line.starts_with("question: "))){
                label+= '\n' + line;
            }
        }

        if(line.starts_with("type: ")){ 
            type = line.substr(strlen("type: "));
            while(getline(fin, line) && !(line.starts_with("question: "))){
                // type+= '\n' + line; //WRONG! Just skip those lines (which are empty since
                                        //type contains only one line of content.)
            }
        }

        //Store all the data collected into the array, after a full question is read.
        questions[questionCount].text = text;
        questions[questionCount].answer = answer;
        questions[questionCount].explanation = explanation;
        questions[questionCount].version = version;
        questions[questionCount].label = label;
        questions[questionCount].type = type;
        questionCount++;

        //Reset variables for a new question
        text = answer = explanation = version = label = type = ""; 
    }
    fin.close();

    int typeCount = 0;
    for(int i = 0; i < questionCount; i++){
        string currentString = questions[i].type;
        int len = currentString.length();
        int startIdx = 0;
        int endIdx = 0;
        for(int idx = 0; idx < len; idx++){
            if(currentString[idx] == ';'){
                endIdx = idx; 
                string newString = currentString.substr(startIdx, endIdx - startIdx);
                append(questionTypes, typeCount, CAPACITY, trim(newString));
                startIdx = endIdx + 1;
            }
        }
        //handle the last string after the semicolon
        append(questionTypes, typeCount, CAPACITY, trim(currentString.substr(startIdx)));
    } 

    //sort the array alphabetically
    sort(questionTypes, questionTypes + typeCount);

    //Get the user to select a type
    printArray(questionTypes, typeCount);
    cout << "Enter a type: ";
    int userTypeIdx;
    cin >> userTypeIdx;
    cin.ignore(); //cin and getline interfering
    if (userTypeIdx <= 0 || userTypeIdx > typeCount + 1){
        cerr << "Selected type is out of bounds.";
        exit(1);
    }
    string newType = questionTypes[userTypeIdx - 1];
    cout << endl;

    int correctQuestionCount = 0;  
    int selectedQuestionCount = 0;
    for(int i = 0; i < questionCount; i++){
        if (questions[i].type.find(newType) != -1){
            selectedQuestionCount++;
            int tries = 0;
            string userAnswer;
            bool correct = false;
            cout << "Question " << i + 1 << ": " << questions[i].text << endl; //i+1 since we start from 0
            do{
                cout << "Enter your answer: ";
                getline(cin, userAnswer);
                tries++;
                cout << "Number of tries: " << tries << endl;
                if (userAnswer == questions[i].answer){
                    correct = true;
                    correctQuestionCount++;
                }
                cout << boolalpha << correct << endl;
            } while(tries < 3 && !correct);
    
            if (tries == 3 && !correct && questions[i].explanation != ""){
                cout << "Answer: " << questions[i].answer << endl <<
                "Explanation: " << questions[i].explanation << endl;
            }        
            cout << endl;   
        }   
    }

    double percentage = (correctQuestionCount) * 100.0 / (selectedQuestionCount);

    cout << "Number of correct problems: " << correctQuestionCount << " out of " << selectedQuestionCount
        << " questions. " << endl;
    cout << "Percentage of correct problems: " << percentage << "%" << endl;

    if (percentage >= 90){
        cout << "Excellent!" << endl;
    }
    else if (percentage >= 80){
        cout << "Good!" << endl;
    }
    else if (percentage >= 60){
        cout << "Pass." << endl;
    }
    else{
        cout << "Please ask for help ASAP." << endl;
    }

    return 0;
}

//FUNCTION DEFINITIONS:
bool exists(string arr[], int size, string element){
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            return true;
        }
    }
    return false;
}

void append(string arr[], int& size, int capacity, string element){
    if(size >= capacity){
        return;
    }
    if(exists(arr, size, element)){
        return;
    }
    arr[size] = element;
    size++;
}

void printArray(string arr[], int size){
    for(int i = 0; i < size; i++){
        cout << i + 1 << ". " << arr[i] << endl;
    }
}

string trim(string string){
    int len = string.length();
    int startIdx = 0;
    int endIdx = len - 1;
    for (int idx = 0; idx < len; idx++){
        if(isspace(string[idx])){
            startIdx++;
        }
        else {
            break;
            //"   a  "
        }
    }
    for (int idx = endIdx; idx > -1; idx--){
        if(isspace(string[idx])){
            endIdx--;
        }
        else {
            break;
        }
    }
    return string.substr(startIdx, endIdx - startIdx + 1);
}