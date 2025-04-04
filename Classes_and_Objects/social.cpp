/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 3, 2025
Assignment: Lab11A

This program declares a class Profile to mimic
a social media profile.
*/


#include <iostream>
#include <string>
using namespace std;

class Profile 
{
    public:
        Profile(string username, string displayname); //create a profile
        string getUsername() const; //accessor member function
        string getFullName() const; //accessor member function
        void setDisplayName(string newDisplayName); //changes the display name given a profile
    private:
        string username;
        string displayname;
};

int main()
{
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
    return 0;
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
    string display = displayname + " (@" + username + ")";
    return display;
}

void Profile::setDisplayName(string newDisplayName)
{
    displayname = newDisplayName;
}