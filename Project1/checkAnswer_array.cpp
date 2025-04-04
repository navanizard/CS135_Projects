/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 13, 2025.
Assignment: Project 1B

This program displays 2 questions and asks the user to answer them. 
If the answer is correct, we display true, otherwise, we display false.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    bool result;
    int correct_count = 0;
    double correct_percent;
    string user_answer;
    string texts[] = {
        "Given char arr[] = {'A', 'B', 'C'}, what is arr[1]?",
        "Given string arr[] = {\"Hello\", \"Hi\", \"Hey\"}, what is arr[2]?",
        "Given two double variables a and b, find out the return of a^b, that is, a raised to the power of b. Hint: use pow function.",
        "Suppose n is properly declared and initialized as an integer. Write a statement to throw away the least significant digit from n. For example, if n is 12, after the statement, n changes to be 1.",
        "Assume that n is properly declared and initialized. Write a statement to declare lastDigit as an integer and initialize it to be the least significant digit of integer n. Suppose n is 123, after the statement, lastDigit is 3.",
        "What is the output?\n#include <iostream>\nusing namespace std;\n\nint main() {\n int count = 0;\n for (int i = -6; i < 2; i += 3)\n count++;\n\n cout << count << endl;\n return 0;\n}",
        "Write a condition to represent that char variable ch is none of the following: 'a', 'b', or 'c'."
    };
    const int SIZE_OF_ARR_TEXTS = sizeof(texts) / sizeof(texts[0]);
    string answers[]{
        "'B'",
        "\"Hey\"",
        "pow(a, b)", 
        "n /= 10;", 
        "int lastDigit = n % 10;",
        "3",
        "(ch != 'a' && ch != 'b' && ch != 'c')"
    };

//Print out the question, user inputs answer, display true or false depending on if it matches expected answer.
    for (int i = 0; i < SIZE_OF_ARR_TEXTS; i++){
        cout << "Question " << i + 1 << ": " << texts[i] << endl;
        cout << "Enter your answer: ";
        getline(cin, user_answer);
        if (user_answer == answers[i]){
            result = 1;
            correct_count++;
        }
        else{
            result = 0;
        }
        //boolalpha prints out "true" or "false" instead of "1" and "0"
        cout << boolalpha << result << endl;
    }
    //Calculation to get percent:
    correct_percent = (correct_count / 7.0) * 100;

    cout << "Number of correct problems: " << correct_count << endl;
    cout << "Percentage of correct: " << correct_percent << "%" << endl;
    //Print comment based on percent:
    if (correct_percent >= 90){
        cout << "Excellent";
    } else if (correct_percent >= 80){
        cout << "Good";
    } else if (correct_percent >= 60){
        cout << "Pass";
    } else{
        cout << "Please ask help ASAP";
    }

    return 0;
}
