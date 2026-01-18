#include <iostream>
#include <cmath>
using namespace std;

/* Bitwise operators can be applied to integral data types : such as int, char, short, long, and their unsigned variants. 
   Types : 
    1. bitwise AND (&)
    2. bitwise OR (|)
    3. bitwise XOR (^)
    4. bitwise NOT (~)
    5. left shift (<<)
    6. right shift (>>)


*/


// Example usage of bitwise operators with different data types
// 1. Bitwise AND (&): 

int bitwiseAndExample(int a, int b) {
    return a & b;
}



// 2. Bitwise OR (|): 
int bitwiseOrExample(int a, int b) {
    return a | b;  
}




// 3. Bitwise XOR (^):
int bitwiseXorExample(int a, int b) {
    return a ^ b;  
}



// 4. Bitwise NOT (~):
int bitwiseNotExample(int a) {
    return ~a;  
}   



// 5. Left Shift (<<):
int leftShiftExample(int a, int shift) {    
    return a << shift;  
}   



// 6. Right Shift (>>):
int rightShiftExample(int a, int shift) {    
    return a >> shift;  
}






// IsPowerOfTwo :

bool IsPowOfTwoUsingLoops(int num){
    if(num<=1){
        return false;
    }   
    while (num > 1){
        if( num % 2 != 0){
            return false;
        }
        num = num / 2;
    }
    return true;
}




bool IspowOfTwoUsingBitwise(int num){
    if(num<=0){ // Note: 0 and negative numbers are not powers of two
        return false;
    }   
    return (num & (num - 1)) == 0;
}






int revInt(int n1){
    int ans = 0, rem;
    bool neg = n1<0;
    n1 = abs(n1);

    while(n1>0){
        rem = n1%10;
        ans = ans*10 + rem;
        n1 /= 10;
    }
    return (neg ? -ans : ans);
}




int main() {

/*    
    int a, b;
    cout<<"Enter first integer: ";
    cin>>a;
    cout<<"Enter second integer: ";
    cin>>b;

    cout << "Bitwise AND of " << a << " & " << b << " = " << bitwiseAndExample(a, b) << "\n";
    cout << "Bitwise OR of " << a << " | " << b << " = " << bitwiseOrExample(a, b) << "\n";
    cout << "Bitwise XOR of " << a << " ^ " << b << " = " << bitwiseXorExample(a,b)<< "\n";
    cout << "Bitwise NOT of " << a << " = " << bitwiseNotExample(a) << "\n";
    cout << "Left Shift of " << a << " << 2 = " << leftShiftExample(a, 2) << "\n";
    cout << "Right Shift of " << a << " >> 2 = " << rightShiftExample(a, 2) << "\n";
    cout << "Left Shift of " << b << " << 2 = " << leftShiftExample(b, 2) << "\n";
    cout << "Right Shift of " << b << " >> 2 = " << rightShiftExample(b, 2) << "\n";

*/  


/*
    cout<<"---------------------Is Power of Two Check (Using Loops)---------------------\n";
    cout<<"Is "<<a<<" a power of two? : "<<(IsPowOfTwoUsingLoops(a) ? "Yes" : "No")<<"\n";
    cout<<"Is "<<b<<" a power of two? : "<<(IsPowOfTwoUsingLoops(b) ? "Yes" : "No")<<"\n";



    cout<<"---------------------Is Power of Two Check (Using Bitwise Operators)---------------------\n";
    cout<<"Is "<<a<<" a power of two? : "<<(IspowOfTwoUsingBitwise(a) ? "Yes" : "No")<<"\n";
    cout<<"Is "<<b<<" a power of two? : "<<(IspowOfTwoUsingBitwise(b) ? "Yes" : "No")<<"\n";

*/



    int n1;
    cout<<"Enter an Integer to reverse : ";
    cin>> n1;

    cout<< "Reverse of " << n1 << " = " << revInt(n1);
    
    return 0;
}
