#include <iostream>
using namespace std;

int main(){
    string m, n, ans = "";
    cin >> m >> n;
    
    // Bruteforce Approach :
    // for(int i = 0; i < m.length(); i++){
    //     if(m[i] == n[i]) ans += '0';
    //     else ans += '1';
    // }
    // cout << ans;

    // Better Approach - Using XOR :
    for(int i = 0; i <m.length(); i++){
        ans += ((m[i] - '0') ^ (n[i] - '0')) + '0';
    }
    cout << ans;
}