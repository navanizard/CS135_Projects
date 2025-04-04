//Lecture slip 4

#include <iostream>
#include <string>
using namespace std;

int main(){
    string num;
    int digits;

    cout << "Enter an integer: ";
    cin >> num;

    digits = num.length();

    cout << "There are " << digits << " digits in the integer you entered.";


    return 0;
}