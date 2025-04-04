#include <iostream>
using namespace std;

int main(){
    int s = 0;
    for(int i = 1; i < 20; i++){
        int t = 0;
        for(int j = i + 2; j < 22; j++){
            t = t + 1;
            s = s + 1;
        }
        cout << t << endl;
    }
    cout << s << endl;
    cout << (19*18) / 2;
    return 0;

}