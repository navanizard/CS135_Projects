#include <iostream>
using namespace std;

int main(){
    const int CAPACITY = 10;
    int arr[CAPACITY];

    //initialize the elements in the array
    int count = 0;
    int num;
    cout << "Enter a list of integers. Ctrl z to exit. Capacity: " << CAPACITY << endl;

    while ((cin >> num) && (count < CAPACITY)){
        arr[count] = num;
        count++;
    }

    //cout << arr; // will print the address of the first element in arr.

    for (int i = 0; i < count; i++){
        cout << arr[i] << " ";
    }

    // //IF you want reverse order. from last element to first
    // for (int i = count - 1; i < count; i--){
    //     cout << arr[i] << " ";
    // }


    return 0;
}



