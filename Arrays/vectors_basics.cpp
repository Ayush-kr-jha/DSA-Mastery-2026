/*
vectors_basics.cpp
Topic: Vectors
Description: Basics of C++ vectors, member functions, and common problems
Includes:
- Initialization
- push_back, pop_back, clear
- front, back, at
- resize
- pass-by-reference vs pass-by-value
- Single Number (Leetcode 136)
- Linear Search
- Reverse vector (2-pointer method)
*/

#include <iostream>
#include <vector>
#include <algorithm> // For swap() and reverse()
using namespace std;

// -------------------------
// Reverse Vector (2-pointer approach)
// -------------------------
void reverseVector(vector<int> &v){ // pass by reference to modify original
    int start = 0, end = v.size() - 1;
    while(start < end){
        swap(v[start], v[end]);
        start++; end--;
    }
}

// -------------------------
// Main Function
// -------------------------
int main() {
    // -------------------------
    // Vector Initialization
    // -------------------------
    vector<int> v; // empty
    cout << "Size of empty vector v = " << v.size() << "\n";

    vector<int> v1 = {1,2,3,4,5};
    cout << "Vector v1 elements: ";
    for(auto val : v1) cout << val << " ";
    cout << "\n";

    vector<int> v2(3, 20); // size 3, all 20
    cout << "Vector v2 elements: ";
    for(auto val : v2) cout << val << " ";
    cout << "\n";

    // -------------------------
    // Vector Member Functions
    // -------------------------
    vector<int> vec;
    vec.push_back(10); vec.push_back(20); vec.push_back(30);
    cout << "\nVector after push_back: ";
    for(auto val : vec) cout << val << " ";
    cout << "\nSize = " << vec.size() << "\n";

    vec.pop_back();
    cout << "Vector after pop_back: ";
    for(auto val : vec) cout << val << " ";
    cout << "\nSize = " << vec.size() << "\n";

    vec.clear();
    cout << "Vector size after clear = " << vec.size() << "\n";

    cout << "\nFirst element of v1 = " << v1.front();
    cout << "\nLast element of v1 = " << v1.back();
    cout << "\nElement at index 2 = " << v1.at(2);

    v1.resize(7); // new elements = 0
    cout << "\nVector v1 after resizing to 7 elements: ";
    for(auto val : v1) cout << val << " ";
    cout << "\nSize = " << v1.size() << "\n";

    // -------------------------
    // Single Number Problem
    // -------------------------
    vector<int> nums = {4,1,2,1,2};
    int singleNumber = 0;
    for(auto val : nums) singleNumber ^= val;
    cout << "\nSingle number in nums = " << singleNumber << "\n";

    // -------------------------
    // Linear Search in Vector
    // -------------------------
    vector<int> vecSearch = {10,20,30,40,50};
    int target = 30;
    bool found = false;
    for(auto val : vecSearch){
        if(val == target){
            found = true;
            break;
        }
    }
    if(found) cout << "Element " << target << " found in vecSearch\n";

    // -------------------------
    // Reverse Vector Example
    // -------------------------
    vector<int> rv = {10,20,30,40,50};
    cout << "\nOriginal vector: ";
    for(auto val : rv) cout << val << " ";

    reverseVector(rv);
    cout << "\nReversed vector: ";
    for(auto val : rv) cout << val << " ";

    cout << "\n";

    return 0;
}
