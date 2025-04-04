/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: March 6, 2025.
Assignment: Lab6B

This program implements Caesar cipher encryption. In a ceaser cipher, each
character is shifted by an indicated value.
(Assumption: rshift is in the range [0, 25].)
*/

#include <iostream>
#include <string>
#include <cctype> //special functions on characters (like isalpha() etc).
using namespace std;

bool isUpperCase(char c);
bool isLowerCase(char c);
char shiftChar(char c, int rshift);
string encryptCaesar(string plaintext, int rshift);

int main(){
    string plaintext;
    cout << "Plaintext: ";
    getline(cin, plaintext);
    int shift;
    cout << "Enter shift: ";
    cin >> shift;
    cout << "Ciphertext: " << encryptCaesar(plaintext, shift) << endl;
    // cout << shiftChar('W', 10);
    // cout << encryptCaesar("Way to Go!", 5);
    return 0; 
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

string encryptCaesar(string plaintext, int rshift){
    string ciphertext;
    int len = plaintext.length();
    for(int i = 0; i < len; i++){
        ciphertext+= shiftChar(plaintext[i], rshift);
        // ciphertext[i] = shiftChar(plaintext[i], rshift); //why is this wrong?
    }
    return ciphertext;
}
