/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 30, 2025
Assignment: Lab13 (Tasks A-F)

This program: 
- Defines a recursive function that prints all numbers 
    in range left ≤ x ≤ right, separated by spaces. 
- Defines a recursive function that computes the sum of all 
    numbers in range left ≤ x ≤ right. 
- Defines a function which receives an array and its size and should return the 
    sum of its elements. The function itself should not do any new dynamic memory allocations.
- Defines a function which returns true if all characters in the string are letters and digits, 
    otherwise returns false.
- Defines a function  which returns true if the string is a sequence of nested parentheses.
- Defines a function that returns true if the collection is divisible, and false otherwise. 
    The prices are provided in the array prices, and size is the number of items in the array.
        - Defines a helper function to generate all possible options/solutions to even distributing
            the collection amongst two people.
*/


#include <iostream>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int* arr, int size);
bool isAlphanumeric(string s);
bool nestedParens(string s);
bool divisible(int* prices, int size);
bool divisionHelper(int* prices, int size, int alice, int bob);

int main(){
    //TEST FUNCTION 1:
    // printRange(-2, 10); // should print -2 -1 0 1 2 3 4 5 6 7 8 9 10

    //TEST FUNCTION 2:
    // int x = sumRange(1, 3);
    // cout << "This is " << x << endl;//6
    // int y = sumRange(-2, 10);
    // cout << "That is " << y << endl;//52
    
    //TEST FUNCTION 3:
    // int size = 10;
    // int *arr = new int[size]; // allocate array dynamically
    // arr[0] = 12;
    // arr[1] = 17;
    // arr[2] = -5;
    // arr[3] = 3;
    // arr[4] = 7;
    // arr[5] = -15;
    // arr[6] = 27;
    // arr[7] = 5;
    // arr[8] = 13;
    // arr[9] = -21;

    // int sum1 = sumArray(arr, size); // Add all elements
    // cout << "Sum is " << sum1 << endl;  // Sum is 43
    
    // int sum2 = sumArray(arr, 5); // Add up first five elements
    // cout << "Sum is " << sum2 << endl;  // Sum is 34

    // delete[] arr;         // deallocate it

    //TEST FUNCTION 4:
    // cout << isAlphanumeric("ABCD") << endl;        // true (1)
    // cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
    // cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)

    //TEST FUNCTION 5:
    // cout << nestedParens("((()))") << endl;      // true (1)
    // cout << nestedParens("()") << endl;          // true (1)
    // cout << nestedParens("") << endl;            // true (1)
  
    // cout << nestedParens("(((") << endl;         // false (0)
    // cout << nestedParens("(()") << endl;         // false (0)
    // cout << nestedParens(")(") << endl;          // false (0)
    // cout << nestedParens("a(b)c") << endl;       // false (0)

    //TEST FUNCTION 6:
    int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    int size = sizeof(prices) / sizeof(prices[0]);
    cout << boolalpha << divisible(prices, size) << endl;
    return 0;
}

void printRange(int left, int right){
    if (right < left){ //if wrong order or same number - then can't print the range
        return;
    }
    if (right == left){
        cout << right << " ";
        return;
    }
    cout << left << " ";
    left++;
    printRange(left, right);
}

int sumRange(int left, int right){
    if (right < left){
        return 0;
    }
    if (right == left){
        return right;
    }
    return left + sumRange(left + 1, right);
}

int sumArray(int* arr, int size){
    if (size == 0){
        return 0;
    }
    //start at the end. add all the elements to the last.
    return arr[size - 1] + sumArray(arr, size - 1);
}

bool isAlphanumeric(string s){
    int size = s.size();
    if (size == 0){
        return true;
    }
    return ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= '0' && s[0] <= '9')) && isAlphanumeric(s.substr(1));
}

bool nestedParens(string s){
    int size = s.size();
    if (size == 0){
        return true;
    }
    //check open and close parentheses
    return (s[0] == '(' && s[size-1] == ')') && nestedParens(s.substr(1, size-2));
}

bool divisible(int* prices, int size){
 // The goal: Check if it's possible to divide the prices array into two groups
    // such that the total sum of each group is equal (Alice and Bob get equal totals).

    // This function acts as a "starter" function, calling the helper with:
    // - the array,
    // - its size,
    // - Alice's current total (starts at 0),
    // - Bob's current total (starts at 0).

    // We use a helper function to keep track of how much Alice and Bob have as we
    // recursively consider each item in the array.    // int total = 0;
    // for (int i = 0; i < size; i++){
    //     total+= i;
    // }

    // if (total % 2 == 0){
    //     return true;
    // }
    // return false;

    return divisionHelper(prices, size, 0, 0);
}

bool divisionHelper(int* prices, int size, int alice, int bob){

    // Base case: If there are no more items left to divide (size == 0),
    // check if Alice and Bob have the same total. If yes, return true (divisible),
    // otherwise return false.
    if (size == 0){
        return alice == bob;
    }

    // Recursive case 1: Give the current item (prices[0]) to Alice.
    // Move to the next item (prices + 1 shifts the pointer forward),
    // decrease size by 1, and add prices[0] to Alice's total.
    if (divisionHelper(prices + 1, size - 1, alice + prices[0], bob)){
        return true;  // if this path leads to a solution, return true.
    }

    // Recursive case 2: Give the current item to Bob instead.
    // Similarly, move to the next item, decrease size by 1,
    // and add prices[0] to Bob's total.
    if (divisionHelper(prices + 1, size - 1, alice, bob + prices[0])){
        return true;  // if this path leads to a solution, return true.
    }

    // If neither option leads to a solution, return false.
    return false;
}