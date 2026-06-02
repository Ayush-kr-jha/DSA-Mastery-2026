#include <iostream>
#include <string>
using namespace std;

int main(){
    string n;
    cin >> n;
    int count = 0;
    for(int i = 0;  i < n.length(); i++){
        if(n[i] == '4' || n[i] == '7') count++;
    }

    string s = to_string(count);
    bool ok = true;
    for(char c : s){
        if( c != '4' && c != '7'){
            ok = false;
            break;
        }
    }
    cout << (ok? "YES" : "NO");
}