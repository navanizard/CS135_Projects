/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 5, 2025.
Assignment: Project 1C

This program reads the data of an exam from a file into a struct array, then displays each question
and asks the user to enter the answer. The user has 3 tries to answer correctly before the 
explanation is displayed and the program moves on to the next question. At the end, it calculates the 
user's grade.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <string.h> //c-style strings
using namespace std;

//To represent a question, we use a struct called Question. In C++, struct is a type that
//may contain different types of elements.Define Question outside a function, so that 
//every function defined after can use it.

struct Question {
    string text, answer, explanation, version, label, type;
};

int main(){
    //Declare an array of Question
    Question questions[250]; 
    int questionCount = 0;
    string line; //To read the file line by line
    string text, answer, explanation, version, label, type;
    

    //Read the data from the file into fin
    string file;
    file = "cs135_midterm_f24_v2.txt";
    // cout << "Enter file name: ";
    // cin >> file;
    ifstream fin(file);
    if (fin.fail()){
        cerr << "File could not be opened.";
        exit(1);
    }

    //Read the data line by line
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
                type+= '\n' + line;
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

    // TEST: Print out contents of the array
    // for (int i = 0; i < questionCount; i++){
    //     Question x = questions[i];
    //     cout << "Question " << i + 1 << ": " << x.text << endl; 
    //     cout << "Answer: " << x.answer << endl;
    //     cout << "Explanation: " << x.explanation << endl;
    //     cout << "Version: " << x.version << endl;
    //     cout << "Label: " << x.label << endl;
    //     cout << "Type: " << x.type << endl;
    //     cout << "--------------------------------------" << endl;
    // }

    int correctQuestionCount = 0;
    //Get user values for test
    for (int i = 0; i < questionCount; i++){
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
        }
        while(tries < 3 && !correct);

        if (tries == 3 && !correct && questions[i].explanation != ""){
            cout << "Answer: " << questions[i].answer << endl <<
            "Explanation: " << questions[i].explanation << endl;
        }        

        cout << endl;   
    }

    double percentage = (correctQuestionCount) * 100.0 / (questionCount);

    cout << "Number of correct problems: " << correctQuestionCount << " out of " << questionCount
        << " questions. " << endl;
    cout << "Percentage of correct problems: " << percentage << "%" << endl;

    if (percentage >= 90){
        cout << "Excellent!";
    }
    else if (percentage >= 80){
        cout << "Good!";
    }
    else if (percentage >= 60){
        cout << "Pass.";
    }
    else{
        cout << "Please ask for help ASAP.";
    }

    return 0;
}
