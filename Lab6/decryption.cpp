/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 9, 2025.
Assignment: Lab6D

This program encrypts and decrypts a user-inputted message using
a Caesar cipher as well as a Vigenere cipher.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Delcare functions:
int shift(char c);
bool isUpperCase(char c);
bool isLowerCase(char c);
char shiftChar(char c, int rshift);
string encryptCaesar(string plaintext, int rshift);
string decryptCaesar(string ciphertext, int rshift);
string encryptVigenere(string plaintext, string keyword);
string decryptVigenere(string ciphertext, string keyword);


int main(){
    string plaintext, caesarCipherText, vigenereCipherText, keyword;
    int rshift;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << endl << "= Caesar =" << endl;
    cout << "Enter shift: ";
    cin >> rshift;
    caesarCipherText = encryptCaesar(plaintext, rshift);
    cout << "Ciphertext: " << caesarCipherText << endl;
    cout << "Decrypted: " << decryptCaesar(caesarCipherText, rshift) << endl;

    cout << endl << "= Vigenere =" << endl;
    cout << "Enter keyword: ";
    cin >> keyword;
    vigenereCipherText = encryptVigenere(plaintext, keyword);
    cout << "Ciphertext: " << vigenereCipherText << endl;
    cout << "Decrypted: " << decryptVigenere(vigenereCipherText, keyword) << endl;
    return 0;
}

int shift(char c){
    return tolower(c) - 'a'; //make sure the shift is calculated from a lowercase char.
}

bool isUpperCase(char c){
    return c >= 'A' && c <= 'Z';
}

bool isLowerCase(char c){
    return c >= 'a' && c <= 'z';
}

//DOESNT HANDLE NEGATIVES ACCURATELY:
// char shiftChar(char c, int rshift){
//     int ascii = (int)c;
//     if (isLowerCase(c)){
//         int offset = ascii + rshift - (int)'a';
//         int wrap = offset % 26;
//         c = (char)((int)'a' + wrap);
//     }
//     if (isUpperCase(c)){
//         int offset = ascii + rshift - (int)'A';
//         int wrap = offset % 26;
//         c = (char)((int)'A' + wrap);
//     }
//    return c;
// }

char shiftChar(char c, int rshift){
    if (isLowerCase(c)) {
        int offset = (c - 'a' + rshift + 26) % 26;  // Adding 26 ensures positive results for negative shifts
        return 'a' + offset;
    }
    else if (isUpperCase(c)) {
        int offset = (c - 'A' + rshift + 26) % 26;  // Same for uppercase letters
        return 'A' + offset;
    }
    return c;  // Non-alphabetic characters are unchanged
}

string encryptCaesar(string plaintext, int rshift){
    string ciphertext;
    int len = plaintext.length();
    for(int i = 0; i < len; i++){
        ciphertext+= shiftChar(plaintext[i], rshift);
        // ciphertext[i] = shiftChar(plaintext[i], rshift); //why is this wrong?
    }
    return ciphertext;
}

string decryptCaesar(string ciphertext, int rshift){
    string plaintext;
    int len = ciphertext.length();
    
    for(int i = 0; i < len; i++){
        char currentChar = ciphertext[i];
        if (isalpha(currentChar)) {
            plaintext+= shiftChar(currentChar, -rshift); //change the shift to negative
        }   
        else{
            plaintext+= currentChar;
        }
    }
    return plaintext;
}

string encryptVigenere(string plaintext, string keyword){
    int plaintext_length = plaintext.length();
    int keyword_length = keyword.length();
    int keyword_idx = 0;
    string ciphertext;
    for (int i = 0; i < plaintext_length; i++){
        char current = plaintext[i];
        if(isalpha(current)){ //process only alphabetic characters
            ciphertext+= shiftChar(current, shift(keyword[keyword_idx]));
            keyword_idx++; //only increment if we used a keyword letter
            if (keyword_idx == keyword_length) { // loop through the keyword
                keyword_idx = 0;
            }
        }
        else{
            ciphertext+= current;
        }
        
    }
    return ciphertext;
}

string decryptVigenere(string ciphertext, string keyword){
    string plaintext;
    int keyword_length = keyword.length();
    int keyword_idx = 0;
    int ciphertext_length = ciphertext.length();
    for(int i = 0; i < ciphertext_length; i++){
        char currentChar = ciphertext[i];
        if(isalpha(currentChar)){
            plaintext+= shiftChar(currentChar, -shift(keyword[keyword_idx])); //change the shift to negative
            keyword_idx++;
            if(keyword_idx == keyword_length){
                keyword_idx = 0;
            }
        }
        else{
            plaintext+= currentChar;
        }
    }
    return plaintext;
}

