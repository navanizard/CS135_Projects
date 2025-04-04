/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 3, 2025
Assignment: Lab11B

This program declares a class Profile and a class Network to mimic
a social media profile.
*/

#include <iostream>
#include <string>
using namespace std;

class Profile 
{
    public:
        Profile(); //default constructor. needed to initialize the array later in network
        Profile(string username, string displayname); //create a profile
        string getUsername() const; //accessor member function
        string getFullName() const; //accessor member function
        void setDisplayName(string newDisplayName); //changes the display name given a profile
    private:
        string username;
        string displayname;
};

class Network 
{
    public:
        Network(); //default constructor. sets numUsers to 0
        bool addUser(string username, string displayname);

    private:
        static int const MAX_USERS = 20;
        Profile profiles[MAX_USERS]; //array with all registered users. ID is the index
        int numUsers; //stores the amount of users
        int findID(string username);

};

bool isAlphaNumeric(string str);

int main() 
{
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)
  
    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)
  
    for(int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i), 
                   "Mario" + to_string(i)) << endl;   // true (1)
  
    cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
    return 0;
}

//PROFILE CLASS IMPLEMENTATION:
Profile::Profile()
{
    username = displayname = "";
}

Profile::Profile(string username, string displayname)
{
    //this is a pointer to the current object.
    //*this is an alias to the current object
    //(*this).side == this->side //need the parentheses since . has higher precendency than dereference
    this->username = username;
    this->displayname = displayname;
}

string Profile::getUsername() const
{
    return username;
}

string Profile::getFullName() const
{
    return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(string newDisplayName)
{
    displayname = newDisplayName;
}

//NETWORK CLASS IMLPEMENTATION:
Network::Network()
{
    numUsers = 0;
}

int Network::findID(string username)
{
    for (int i = 0; i < numUsers; i++){
        if (profiles[i].getUsername() == username){
            return i;
        }
    }
    return -1;
}

bool Network::addUser(string username, string displayname)
{
    if (username.empty() || findID(username) != -1 || numUsers >= MAX_USERS || !isAlphaNumeric(username)){
        return false;
    }
    profiles[numUsers] = Profile(username, displayname);
    numUsers++;
    return true;
}

bool isAlphaNumeric(string str)
{
    for (int i = 0; i < str.length(); i++){
        char c = str[i];
        if (!((c >= 'A' && c <= 'z') || 
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'))) {
                return false;
            }
    }
    return true;
}