#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;

    while(t--){
        for(int i = 0; i < n-1; i++){
            if (s[i] == 'B' && s[i+1] == 'G'){
                swap(s[i+1], s[i]);
                i++; //In one second, each person can move at most once. So skip next position or to ensure only 1 swapping for 1 pair (B and G)
            }
        }
    }
    cout << s;
}