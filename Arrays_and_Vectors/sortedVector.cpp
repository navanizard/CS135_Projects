/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 28, 2025
Assignment: Homework E6.20

This program implements a function that returns a sorted vector with all the elements
of two given vectors.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b);

int main(){
    vector<int> a1{1, 4, 9, 16};
    vector<int> a2{4, 7, 9, 9, 11};
    vector<int> a3 = merge_sorted(a1, a2);
    for (int i = 0; i < a3.size(); i++){
        cout << a3[i] << " ";
    }

    return 0;
}

vector<int> merge_sorted(vector<int> a, vector<int> b){
    int c_size = a.size() + b.size(); 
    vector<int> c(c_size);

    int a_idx = 0; //idx of where we are in the a vector
    int b_idx = 0; //idx of where we are in the b vector
    int c_idx = 0; //idx of where we are in the c vector

    while (a_idx < a.size() && b_idx < b.size()){
        if(a[a_idx] < b[b_idx]){
            c[c_idx] = a[a_idx];
            a_idx++;
            c_idx++;
        }
    
        else if(a[a_idx] > b[b_idx]){
            c[c_idx] = b[b_idx];
            b_idx++;
            c_idx++;
        }
    
        else{ //if they're equal / the same element
            c[c_idx] = a[a_idx];
            c[c_idx+1] = b[b_idx];
            a_idx++;
            b_idx++;
            c_idx+= 2;
        }
    }

    //once outside the loop, it means either that no more elms in a or no more elms in b
    while(a_idx < a.size()){ //if there are still elms in a
        c[c_idx] = a[a_idx]; //add them to c
        a_idx++;
        c_idx++;
    }

    while(b_idx < b.size()){ //if there are still elms in b
        c[c_idx] = b[b_idx]; //add them to c
        b_idx++;
        c_idx++;
    }

    return c; //return the merged vector

}