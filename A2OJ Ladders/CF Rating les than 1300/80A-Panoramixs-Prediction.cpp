#include <iostream>
using namespace std;


bool isPrime(int x){
    if(x < 2) return false;
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}


int main(){
    int n , m;
    cin >> n >> m;
    bool flag = true;

    if(isPrime(m)){
        for(int i = n+1; i < m; i++){
            if(isPrime(i)){
                cout << "NO";
                flag = false;
                break;
            }
        }
        
        if(flag) cout << "YES";
    }else{
        cout << "NO";
    }
}


/*
Another Approach :

#include <iostream>
using namespace std;

bool isPrime(int x){
    if(x < 2) return false;
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}



int main() {
    int n, m;
    cin >> n >> m;

    if(isPrime(m)){
        while(true){
            n++;
            if(isPrime(n)) break;
        }
    }else{
        cout << "NO";
        return 0;
    }

    if(n == m) cout << "YES";
    else cout << "NO";
    
}
*/