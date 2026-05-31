#include <iostream>
using namespace std;

int main(){
    int m[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}

    };

    int a[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[i][j] ; 
        }
    }


    int dx[] = {0, 1, -1, 0, 0};
    int dy[] = {0, 0, 0, 1, -1};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a[i][j] % 2 == 1){
                for(int k = 0; k < 5; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];


                    if(ni >= 0 && ni < 3 && nj >= 0 && nj < 3){
                        if(m[ni][nj] == 1) m[ni][nj] = 0;
                        else m[ni][nj] = 1;
                    }
                }
            } 
        }
    }


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << m[i][j]; 
        }
        cout << "\n";
    }

}





// SIMPLE APPROACH : 

/*

#include <iostream>
using namespace std;

int main(){
    
    int a[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int b[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> b[i][j];
        }
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(b[i][j] % 2 != 0){
                a[i][j] ^= 1;
                if((i+1) < 3)
                    a[i+1][j] ^= 1;
                if((j+1) < 3)
                    a[i][j+1] ^= 1;
                if((i-1) >= 0)
                    a[i-1][j] ^= 1;
                if((j-1) >= 0)
                    a[i][j-1] ^= 1;
            }
                    
        }
    }
    
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
    
}

*/