#include <iostream>
#include <cctype>   // important header
using namespace std;

int main(){
    string s;
    cin >> s;

    int lc = 0, uc = 0;
    for(int i = 0; i < s.length(); i++){
        if(isupper(s[i])) uc++;
        else if(islower(s[i])) lc++;
    }
    if( uc > lc ) {
        for(int i = 0; i < s.length(); i++) s[i] = toupper(s[i]);
    }else{
        for(int i = 0; i < s.length(); i++) s[i] =  tolower(s[i]);
    }

    cout << s;
}