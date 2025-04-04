/*
Author: Nava Karine Nizard
Course: CSCI-135
Instructor: Professor Tong Yi
Date: February 26, 2025.
Assignment: Lab5 (Tasks A-G)

This program:
> Defines a function isDivisibleBy, which tests if n is divisible by d.
> Defines a function isPrime, which tests if an integer is a prime number.
> Defines a funtion nextPrime, which returns the smallest prime greater than n.
> Defines a function countPrimes, which returns the number of prime numbers in the interval a ≤ x ≤ b. 
> Defines a function isTwinPrime, which determines whether or not its argument is a twin prime.
> Defines a function nextTwinPrime, which returns the smallest twin prime greater than n.
> Defines a function largestTwinPrime, which returns the largest twin prime in the range a ≤ N ≤ b.
*/

#include <iostream>
#include <cmath>
using namespace std;

bool isDivisibleBy(int n, int d);
bool isPrime(int n);
int nextPrime(int n);
int countPrimes(int a, int b);
bool isTwinPrime(int n);
int nextTwinPrime(int n);
int largestTwinPrime(int a, int b);

int main(){
    cout << largestTwinPrime(5, 18) << endl;
    cout << largestTwinPrime(1, 31) << endl;
    cout << largestTwinPrime(14, 16) << endl;
    return 0;
}

bool isDivisibleBy(int n, int d){
    if (d == 0){
        cerr << "Error: Division by zero is undefined.";
        return false;
    }
    return n % d == 0;
}

bool isPrime(int n){
    //A number is prime if its only factors are 1 and itself.
    if (n <= 1){
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }

    return true;
}

int nextPrime(int n){
    int i = n + 1; //smallest prime GREATER than n. can be anything from n + 1
    while(true){ //keeps running until there's a value to return.
        if (isPrime(i)){
            return i;
        }
        i++;
    }
}

int countPrimes(int a, int b){
    int primeCount = 0;
    for(int i = a; i <= b; i++){
        if(isPrime(i)){
            primeCount++;
        }
    }
    return primeCount;
}

bool isTwinPrime(int n){
    // A prime number N is called a twin prime if either N-2 or N+2 (or both of them) is also a prime.
    if(isPrime(n) && (isPrime(n+2) || isPrime(n-2))){
        return true;
    }
    
    return false;
}

int nextTwinPrime(int n){
    int i = n + 1;
    while(true){
        if(isTwinPrime(i)){
            return i;
        }
        i++;
    }
}

int largestTwinPrime(int a, int b) {
    for (int i = b; i >= a; i--) { // Loop from b downward
        if (isTwinPrime(i)) {
            return i;
        }
    }
    return -1;
}

//ALTERNATIVE:
// int largestTwinPrime(int a, int b){
//     int currentMax = -1;
//     for(int i = a; i <= b; i++){
//         if(isTwinPrime(i)){
//             currentMax = i;
//         }
//     } 
//     return currentMax; 
// }
//PROBLEM WITH ABOVE APPROACH: too slow. if looking for max, count backwards.