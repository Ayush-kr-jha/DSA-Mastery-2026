#include <iostream>
#include <cmath>
using namespace std;

/* =========================
   Bit Manipulation & Number Tricks
   =========================

   Topics covered:
   1. Bitwise Operators (&, |, ^, ~, <<, >>)
   2. Check if number is power of two
   3. Reverse integer
   4. Count set bits
   5. Check odd/even
   6. Swap two numbers using XOR
*/

//////////////////////////
// 1️. Bitwise Operators //
//////////////////////////

int bitwiseAnd(int a, int b) { return a & b; }
int bitwiseOr(int a, int b) { return a | b; }
int bitwiseXor(int a, int b) { return a ^ b; }
int bitwiseNot(int a) { return ~a; }
int leftShift(int a, int shift) { return a << shift; }
int rightShift(int a, int shift) { return a >> shift; }

/////////////////////////////
// 2️. Check Power of Two   //
/////////////////////////////

bool isPowerOfTwoLoop(int num) {
    if(num <= 1) return false;
    while(num > 1) {
        if(num % 2 != 0) return false;
        num /= 2;
    }
    return true;
}

bool isPowerOfTwoBitwise(int num) {
    if(num <= 0) return false; // 0 and negatives are not powers of two
    return (num & (num - 1)) == 0;
}

//////////////////////////
// 3️. Reverse Integer   //
//////////////////////////

int reverseInt(int n) {
    int ans = 0, rem;
    bool neg = n < 0;
    n = abs(n);
    while(n > 0){
        rem = n % 10;
        ans = ans * 10 + rem;
        n /= 10;
    }
    return (neg ? -ans : ans);
}

//////////////////////////
// 4️. Count Set Bits   //
//////////////////////////

int countSetBits(int n) {
    int count = 0;
    while(n) {
        n &= (n - 1); // remove last set bit
        count++;
    }
    return count;
}

//////////////////////////
// 5️. Odd / Even Check //
//////////////////////////

bool isOdd(int n) { return n & 1; }
bool isEven(int n) { return !(n & 1); }

//////////////////////////
// 6️. Swap using XOR   //
//////////////////////////

void swapXOR(int &a, int &b) {
    if(a != b) { // avoid zeroing if same variable
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

//////////////////////////
// Main Function         //
//////////////////////////

int main() {
    int a = 9, b = 14;

    cout << "Bitwise Operations between " << a << " and " << b << ":\n";
    cout << "AND: " << bitwiseAnd(a,b) << "\n";
    cout << "OR: " << bitwiseOr(a,b) << "\n";
    cout << "XOR: " << bitwiseXor(a,b) << "\n";
    cout << "NOT a: " << bitwiseNot(a) << "\n";
    cout << "a << 2: " << leftShift(a,2) << "\n";
    cout << "b >> 2: " << rightShift(b,2) << "\n\n";

    cout << "Power of Two Check:\n";
    cout << a << " -> " << (isPowerOfTwoLoop(a) ? "Yes" : "No") << " (Loop)\n";
    cout << b << " -> " << (isPowerOfTwoBitwise(b) ? "Yes" : "No") << " (Bitwise)\n\n";

    cout << "Integer Reversal:\n";
    int nums[] = {123, -456, 1000};
    for(int n : nums) cout << n << " reversed = " << reverseInt(n) << "\n";
    cout << "\n";

    cout << "Count Set Bits:\n";
    for(int n : nums) cout << n << " has " << countSetBits(abs(n)) << " set bits\n";
    cout << "\n";

    cout << "Odd / Even Check:\n";
    for(int n : nums) cout << n << " -> " << (isOdd(n) ? "Odd" : "Even") << "\n";
    cout << "\n";

    cout << "Swap using XOR:\n";
    int x = 5, y = 10;
    cout << "Before swap: x=" << x << ", y=" << y << "\n";
    swapXOR(x,y);
    cout << "After swap: x=" << x << ", y=" << y << "\n";

    return 0;
}
