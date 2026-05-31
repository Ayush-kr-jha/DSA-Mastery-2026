#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    
    while(true){
        n++;
        string s = to_string(n);

        bool distinct = true;
        for(int i = 0; i < 4; i++){
            for(int j = i+1; j < 4; j++){
                if (s[i] == s[j]){
                    distinct = false;
                }
            }
        }

        if(distinct){
            cout << n;
            break;
        }
    }
}