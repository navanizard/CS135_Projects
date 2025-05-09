/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: April 28, 2025
Assignment: Lab12D

This program that implements a function that returns a vector of integers whose elements 
are the pairwise sum of the elements from the two vectors passed as arguments.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2);
void printVector(vector<int> v);

int main(){
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};
    vector<int> v3 = sumPairWise(v1, v2); // returns [5, 7, 3]
    printVector(v3);
    return 0;
}

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2)
{
    vector<int> v3;

    int v1_size = v1.size();
    int v2_size = v2.size();

    for (int i = 0; i < max(v1_size, v2_size); i++){
        int v1_num = 0; //otherwise, set to 0 (if no more elms in the vectors)
        int v2_num = 0;

        if(i < v1_size){ //if there are still elms in v1
            v1_num = v1[i];
        }
        if(i < v2_size){ //if there are still elms in v2
            v2_num = v2[i];
        }
        v3.push_back(v1_num + v2_num);
    }
    // //CASE 1: v1 > v2
    // if(v1_size > v2_size){
    //     for (int i = 0; i < v2_size; i++){
    //         v3.push_back(v1[i] + v2[i]);
    //     }
    //     for (int i = v2_size; i < v1_size; i++){
    //         v3.push_back(v1[i]);
    //     }   
    // }

    // //CASE 2: v1 < v2
    // if(v1_size < v2_size){
    //     for (int i = 0; i < v1_size; i++){
    //         v3.push_back(v1[i] + v2[i]);
    //     }
    //     for (int i = v1_size; i < v2_size; i++){
    //         v3.push_back(v2[i]);
    //     }   
    // }

    // //CASE 3: v1 == v2
    // if(v1_size == v2_size){
    //     for (int i = 0; i < v1_size; i++){
    //         v3.push_back(v1[i] + v2[i]);
    //     }
    // }

    return v3;
}

void printVector(vector<int> v){
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++){
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]"; //edge case - last elm (no comma)
}
