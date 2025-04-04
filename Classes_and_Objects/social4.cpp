/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 3, 2025
Assignment: Lab11D

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

struct Post
{
    string username, message;
};

class Network 
{
    public:
        Network(); //default constructor. sets numUsers to 0
        bool addUser(string username, string displayname);
        bool follow(string username1, string username2); //user1 follows user2
        void printDot(); //print out a digraph of users, and who follows whom
        bool writePost(string username, string message); //add a new post
        bool printTimeline(string username);

    private:
        static int const MAX_USERS = 20;
        static int const MAX_POSTS = 100;
        Profile profiles[MAX_USERS]; //array with all registered users. ID is the index
        int numUsers; //stores the amount of users
        int numPosts; //number of posts
        Post posts[MAX_POSTS]; //array of all posts
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
     
    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
  
    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");
  
    cout << endl;
    cout << "======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;
  
    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;
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
    numPosts = 0;
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

bool Network::writePost(string username, string message)
{
    if (findID(username) == -1 || numPosts >= MAX_POSTS){
        return false;
    }
    posts[numPosts].username = username;
    posts[numPosts].message = message;
    numPosts++;
    return true;
}

bool Network::printTimeline(string username)
{
    if (findID(username) == -1){
        cout << "Error: Could not find user in Network.";
        return false;
    }

    int userID = findID(username);
    //loop through all posts
    for (int i = numPosts - 1; i >= 0; i--){
        //if username posted that post of if someone username follows posted the post, print it
        if (posts[i].username == username || following[userID][findID(posts[i].username)]){
            cout << profiles[findID(posts[i].username)].getFullName() << ": " << posts[i].message << endl;
        }
    }

    return true;
}
