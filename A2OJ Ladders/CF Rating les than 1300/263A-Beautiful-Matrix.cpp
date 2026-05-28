#include <iostream>
using namespace std;

int main(){
    int x, val = 0;
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            cin >> x;
            if (x == 1) {
                // if ( i > 3 ) val += i-3;
                // if ( i < 3 ) val += 3-i;
                // if ( j > 3 ) val += j-3;
                // if ( j < 3 ) val += 3-j;

                val = abs(i-3) + abs(j-3);
            }
        }
    }
    cout << val;
}