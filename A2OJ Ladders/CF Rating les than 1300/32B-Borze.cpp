#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string val;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '.') val += '0';
        else if(s[i] == '-'){
            if(s[i+1] == '.')   val += '1';
            else if(s[i+1] == '-') val += '2';
            i++; // skip the next character
        } 
    }

    cout << val;
}