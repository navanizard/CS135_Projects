/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 9, 2025.
Assignment: Lab6C

This program implements Vigenere cipher encryption. Each letter of the plaintext
is shifted by a value indicated in an alphabetic keyword.
*/

#include <iostream>
#include <string>
#include <cctype> //functions on characters (like isalpha() etc.)
using namespace std;

int shift(char c);
bool isUpperCase(char c);
bool isLowerCase(char c);
char shiftChar(char c, int rshift);
string encryptVigenere(string plaintext, string keyword);

int main(){
    string plaintext, keyword;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter keyword: ";
    cin >> keyword;
    cout << "Ciphertext: " << encryptVigenere(plaintext, keyword) << endl;
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
char shiftChar(char c, int rshift){
    int ascii = (int)c;
    if (isLowerCase(c)){
        int offset = ascii + rshift - (int)'a';
        int wrap = offset % 26;
        c = (char)((int)'a' + wrap);
    }
    if (isUpperCase(c)){
        int offset = ascii + rshift - (int)'A';
        int wrap = offset % 26;
        c = (char)((int)'A' + wrap);
    }
   return c;
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

