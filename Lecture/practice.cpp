#include <iostream>
#include <string>

using namespace std;

int main(){
    string fullname;
    string firstName;
    string lastName;
    getline(cin, fullname);

    int len = fullname.length();

    for (int i = 0; i < len; i++){
        if (fullname[i] == ' '){ //character is denoted with single quotes
            firstName = fullname.substr(0, i);
            lastName = fullname.substr(i+1, len-1);
        }
    }
    cout << lastName << "," << firstName;


    return 0;
}

//ALternate: 
//cin << firstname << lastname;