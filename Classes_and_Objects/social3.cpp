/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 3, 2025
Assignment: Lab11C

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
        bool follow(string username1, string username2);
        void printDot();

    private:
        static int const MAX_USERS = 20;
        Profile profiles[MAX_USERS]; //array with all registered users. ID is the index
        int numUsers; //stores the amount of users
        int findID(string username);
        bool following[MAX_USERS][MAX_USERS]; //following[id1][id2] == true when id1 is following id2

};

bool isAlphaNumeric(string str);

int main() 
{
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
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
    //initialize nobody following each other
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
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

bool Network::follow(string username1, string username2)
{
    //if the users dont exist in the network
    if (findID(username1) == -1 || findID(username2) == -1){
        return false;
    }

    following[findID(username1)][findID(username2)] = true;
    return true;

}

void Network::printDot()
{
    cout << "digraph {" << endl;
    for(int i = 0; i < numUsers; i++){
        cout << " " << "\"@" << profiles[i].getUsername() << "\"" << endl;
    }
    for (int i = 0; i < numUsers; i++){
        for (int j = 0; j < numUsers; j++){
            if (following[i][j]){
                // i = id of username1
                // j = id of username2
                cout << " " << "\"@" << profiles[i].getUsername() << "\" -> \"@" <<
                    profiles[j].getUsername() << "\"" << endl;
            }
        }
    }
    cout << "}";
}