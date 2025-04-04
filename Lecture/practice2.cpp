#include <iostream>
using namespace std;

int main(){
    double value;
    bool done = false;

    while(!done){
        cin >> value;
        if (cin.fail()){
            done = true;
        }
        else{
            cout << value;
        }
    }
    return 0;
}