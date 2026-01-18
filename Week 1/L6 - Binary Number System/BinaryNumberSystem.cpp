#include <iostream>

using namespace std;

// Decimal to Binary : 
int DecToBin(int decNum){
    int ans = 0, pow = 1;
    int rem;
    while(decNum > 0){
        rem = decNum%2;
        decNum /= 2;
        ans += pow*rem;
        pow *= 10;
    }
    return ans;
}






// Binary to Decimal : 
int BinToDec(int binNum){
    int ans = 0, pow = 1;
    int rem;
    while(binNum > 0){
        rem = binNum%10;
        ans += rem*pow;
        pow *= 2;
        binNum /=10;
    }
    return ans;
}







int main(){

    // Decimal to Binary : 

    /*
    int num;
    cout<<"Enter a decimal number = ";
    cin>>num;
    cout<<"Binary form of "<<num<< " = "<<DecToBin(num)<<"\n\n";


    // 0 to 10 Decimal to Binary conversion : 
    for(int i = 0; i<=10; i++){
        cout<<"Binary form of "<<i<< " = "<<DecToBin(i)<<"\n";
    }

    */




    /*

    // Binary to Decimal : 
    int num1;
    cout<<"Enter a Binary number = ";
    cin>>num1;
    cout<<"Decimal form of "<<num1<< " = "<<BinToDec(num1)<<"\n\n";


    // 0 to 10 Decimal to Binary conversion : 
    int result;
    for(int i = 0; i<=10; i++){
        result = DecToBin(i);
        cout<<"Decimal form of "<<result<< " = "<<BinToDec(result)<<"\n";
    }
    

    */



    return 0;
}
