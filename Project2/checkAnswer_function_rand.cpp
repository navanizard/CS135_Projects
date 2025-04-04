/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 2, 2025.
Assignment: Project 2B

This program continues to organize Project1 into functions, as oppose to having 
all the code in the main function. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cctype> //isspace()
#include <cstdlib> //rand() and srand()
#include <ctime>
using namespace std;

struct Question 
{
    string text, answer, explanation, type, version, label;
};

void read_file(string fileName, Question ques[], int capacity, int& size);
string trim(string str);
int count_occurrences(string str, char ch);
string* extract_type(string type, int& num_types_curr_item);
void insert_order_unique(string type[], int type_capacity, int& type_count, 
                        string toAdd);
void insert_order_unique(string type[], int type_capacity, int& type_count, 
                        Question ques[], int& ques_size);
string choose_type(string* types, int type_count);
void randomize(Question ques[], int size);
void feedback(int num_correct, int num_questions);
void answer_by_type(Question ques[], int size, string chosen_type);

int main() 
{
    const int CAPACITY = 1000;
    int questionCount = 0;
    Question ques[CAPACITY];
    // read_file("cs135_midterm_f24_v1.txt", ques, CAPACITY, questionCount);
    // read_file("cs135_midterm_f24_v2.txt", ques, CAPACITY, questionCount);
    // read_file("cs135_midterm_s24_v1.txt", ques, CAPACITY, questionCount);
    read_file("cs135_final_f24_v1.txt", ques, CAPACITY, questionCount);


    const int TYPE_CAPACITY = 30;
    string types[TYPE_CAPACITY];
    int typeCount = 0;

    insert_order_unique(types, TYPE_CAPACITY, typeCount, ques, questionCount);
    string userType = choose_type(types, typeCount);
    answer_by_type(ques, questionCount, userType);
    return 0;
}

//Read the data from a txt file into a Question array
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

//Trims all white spaces preceding and following text
string trim(string str)
{
    int len = str.length();
    int startIdx = 0;
    int endIdx = len - 1;

    while(isspace(str[startIdx])){
        startIdx++;
    }
    while(isspace(str[endIdx])){
        endIdx--;
    }

    return str.substr(startIdx, endIdx - startIdx + 1);
}

//Counts the occurences of a specified char in a string
int count_occurrences(string str, char ch) 
{
    int len = str.length();
    int count = 0;
    for (int i = 0; i < len; i++){
        if (str[i] == ch){
            count++;
        }
    }
    return count;
}

//Create a dynamically allocated array with all the types
string* extract_type(string type, int& num_types_curr_item)
{
    num_types_curr_item = count_occurrences(type, ';') + 1; //amount of types in this line
    string* types_array = new string[num_types_curr_item]; //create a DA array with the size of the types
    int len = type.length();
    int typeCount = 0;
    int startIdx = 0;
    int endIdx = 0;
    for (int i = 0; i < len; i++){ //loop through the string
        if (type[i] == ';') { //when you find a semicolon
            endIdx = i;
            string newString = type.substr(startIdx, endIdx - startIdx); //get substring before ';'
            types_array[typeCount] = trim(newString);
            typeCount++;
            startIdx = endIdx + 1; //after the semicolon
        }
    }
    types_array[typeCount] = trim(type.substr(startIdx)); //handle the last string after the semicolon
    typeCount++;
    return types_array;
}

//Adds the type to a sorted array in the correct position.
void insert_order_unique(string type[], int type_capacity, int& type_count, 
                        string toAdd)
{
    if (type_count >= type_capacity){ //if there's not sufficient space, leave
        return;
    }

    for (int i = 0; i < type_count; i++){ //loop through the array
        if(type[i] == toAdd){ //no duplicates
            return;
        }
        if(type[i] > toAdd){ //if toAdd comes before the curr type
            for(int j = type_count; j > i; j--){ //loop through the rest of the types backwards
                type[j] = type[j - 1]; //shift all the elements to the right to make space
            }
            type[i] = toAdd; 
            type_count++;
            return;
        }
    }
    type[type_count] = toAdd;
    type_count++;

}

void insert_order_unique(string type[], int type_capacity, int& type_count, 
                        Question ques[], int& ques_size)
{
    for (int i = 0; i < ques_size; i++){ //loop through every question in the Question array
        int curr_type_count = 0;
        string *type_array = extract_type(ques[i].type, curr_type_count); //extarct the types into a DA array
        for(int j = 0; j < curr_type_count; j++){
            insert_order_unique(type, type_capacity, type_count, type_array[j]); //insert each type into the
        }                                                                       //bigger array
        delete[] type_array;
    }

}

//Returns the user chosen type after printing out a list of types to select from
string choose_type(string* types, int type_count)
{
    cout << "0. ALL TYPES" << endl;
    for (int i = 0; i < type_count; i++){
        cout << i + 1 << ". " << types[i] << endl;
    }

    int userType;
    do{
        cout << "Enter a type: ";
        cin >> userType;
    } while(userType < 0 || userType > type_count);
    cin.ignore(); //cin and getline interfering
    if (userType == 0){
        return "";
    }
    else{
        return types[userType - 1];
    }
}

//Shuffle and randomize each question in the Question array
void randomize(Question ques[], int size)
{
    int numToRandomize = size;
    srand(time(NULL));
    while (numToRandomize > 1){ //when there's one element left, no need to shuffle
        int rand_int = rand() % numToRandomize; //pick a random idx from the first numToRandomize elements
        Question temp = ques[rand_int];
        ques[rand_int] = ques[numToRandomize - 1]; //swap the chosen element with the last unshuffled
        ques[numToRandomize - 1] = temp;          // element (numToRandomize - 1)
        numToRandomize--; //now the last one is in place, so reduce the range
    }
}

//Calculates the percentage and corresponding feedback based on the score
void feedback(int num_correct, int num_questions)
{
    cout << "Number of correct answers: " << num_correct << " out of " <<
        num_questions << " questions." << endl;
    double percentage = num_correct * 100.0 / num_questions;
    cout << "Percentage of correct problems: " << percentage << "%" << endl;

    if (percentage >= 90){
        cout << "Excellent!" << endl;
    }
    else if(percentage >= 80){
        cout << "Good!" << endl;
    }
    else if(percentage >= 70){
        cout << "Pass." << endl;
    }
    else{
        cout << "Please ask help ASAP." << endl;
    }
}

//Simulate a question by question test based on user-given type
void answer_by_type(Question ques[], int size, string chosen_type)
{
    int correctQuestionCount = 0;
    int selectedQuestions = 0;
    for (int i = 0; i < size; i++){
        if (ques[i].type.find(chosen_type) != -1){
            selectedQuestions++;
            int tries = 0;
            bool correct = false;
            string userAnswer;
            cout << "Question " << i + 1 << "." << endl;
            cout << ques[i].text << endl;
            do{
                cout << "Enter your answer: ";
                getline(cin, userAnswer);
                tries++;
                cout << "Number of tries: " << tries << endl;
                if (userAnswer == ques[i].answer){
                    correct = true;
                    correctQuestionCount++;
                }
                cout << boolalpha << correct << endl;
            } while(tries < 3 && !correct);

            if (tries == 3 && !correct && ques[i].explanation != ""){
                cout << "Answer: " << ques[i].answer << endl << "Explanation: " << 
                ques[i].explanation << endl;
            }

            cout << endl;
        }
    }
    feedback(correctQuestionCount, selectedQuestions);
}
