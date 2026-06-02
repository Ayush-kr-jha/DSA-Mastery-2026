#include <iostream>
using namespace std;

int main(){
    int n, maxH = 0, minH = 101, maxHidx, minHidx, ans = 0;
    cin >> n;
    int m[n];

    for(int i = 0; i < n; i++){
        cin >> m[i];
    }


    for(int i = 0; i < n; i++){
        if(m[i] > maxH){ // first occurence of maxH
            maxH = m[i];
            maxHidx = i;
        } 
        if(m[i] <= minH){ // last occurence of minH
            minH = m[i];
            minHidx = i;
        } 
    }

    if(maxHidx > minHidx){
        ans += ((maxHidx-0) + ((n-1)-minHidx) - 1);
    }else{
        ans += (maxHidx-0) + ((n-1)-minHidx);
    }

    cout << ans;
}



// > → first maximum
// >= → last maximum
// < → first minimum
// <= → last minimum