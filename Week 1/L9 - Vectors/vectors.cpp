#include <iostream>
#include <vector> // To use vector we've to include Vector header file.
#include <algorithm> // For using swap() function
using namespace std;






// Reversing a Vector using a  void function , i.e. we've to do pass by reference here to reflect changes outside the function :
    void reverseVector(vector<int> &rv){ // Pass by reference to modify the original vector
        int start = 0, end = rv.size() - 1;
        while(start < end){
            swap(rv[start], rv[end]);
            start++;
            end--;
        }
    }




    // reverse a vector using the built-in reverse function from algorithm header file :
    /*
    #include <algorithm> // Required for std::reverse
    void reverseVector(vector<int> &rv){
        reverse(rv.begin(), rv.end()); // Using built-in reverse function
    }
    */  


int main(){
    /*  Vectors in C++ STL (Standard Template Library) :
        - Vectors are Dynamic Arrays (can grow and shrink in size).
        - They provide random access to elements.
        - They are implemented as templates, allowing them to store any data type.
        - Vectors manage memory automatically (no need to manually allocate or deallocate memory).    
        - Vectors provide various member functions for easy manipulation (e.g., push_back, pop_back, size, etc.).
    */



    // Ways to Initialize Vectors :
    // 1. 
    vector <int> v; // Empty Vector of integers
    cout << "Size of vector v = " << v.size() << "\n"; // size() function returns the number of elements in the vector.

    // 2.
    vector <int> v1 = {1,2,3,4,5}; // Vector initialized with values
    cout << "Size of vector v1 = " << v1.size() << "\n";
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " "; // Accessing elements using index
    }

    // 3.
    vector <int> v2(3,20); // Vector of size 3, initialized with value 20
    cout << "\nSize of vector v2 = " << v2.size() << "\n";
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }   





    /*
    Output :    Size of vector v = 0
    Size of vector v1 = 5   
    1 2 3 4 5
    Size of vector v2 = 3   
    20 20 20


    **For-each loop can also be used to iterate through vector elements as shown below :
    for(auto element : v1){
        cout << element << " ";
    }
    
    
    How it works:
    - The for-each loop iterates over each element in the vector v1.        
    - The keyword 'auto' automatically deduces the type of 'element' based on the type of elements stored in the vector (in this case, int).
    - In each iteration, 'element' takes the value of the current element in the vector.
    - This allows us to easily access and print each element without needing to manage indices manually.
    1 2 3 4 5
    20 20 20

    
    
    */



    // Commonly used Vector Member Functions :
    vector <int> vec; // Empty vector

    // Adding elements to the vector using push_back() function : 
    vec.push_back(10); // Adds 10 at the end
    vec.push_back(20); // Adds 20 at the end
    vec.push_back(30); // Adds 30 at the end

    cout << "\nVector elements after push_back operations: ";
    for(auto val : vec){
        cout << val << " ";
    }
    cout << "\nSize of vector vec = " << vec.size() << "\n";



    // Removing elements from the vector using pop_back() function : 
    vec.pop_back(); // Removes the last element
    cout << "Vector elements after pop_back operation: ";
    for( auto val : vec){
        cout << val << " ";
    }

    cout << "\nSize of vector vec after pop_back = " << vec.size() << "\n";


    // Removing all elements from the vector using clear() function : 
    vec.clear(); // Removes all elements
    cout << "Size of vector vec after clear = " << vec.size() << "\n";



    // Accesing the first and last elements using front() and back() functions :
    cout << "\nFirst element of v1 = " << v1.front() << "\n"; // First element
    cout << "Last element of v1 = " << v1.back() << "\n"; // Last element

    // Note: front() and back() functions should be used only when the vector is not empty to avoid undefined behavior.


    // Accessing elements using at() function :
    cout << "\nElement at index 2 in v1 using at() = " << v1.at(2) << "\n"; // Element at index 2

    // Resizing the vector using resize() function :
    v1.resize(7); // Resizes vector to size 7, new elements initialized to 0
    cout << "\nVector v1 after resizing to 7 elements: ";   
    for(auto val : v1){
        cout << val << " ";
    }
    cout << "\nSize of vector v1 after resizing = " << v1.size() << "\n";



    /*
    Output :
    Vector elements after push_back operations: 10 20 30
    Size of vector vec = 3
    Vector elements after pop_back operation: 10 20
    Size of vector vec after pop_back = 2
    Size of vector vec after clear = 0
    First element of v1 = 1
    Last element of v1 = 5
    Element at index 2 in v1 using at() = 3
    Vector v1 after resizing to 7 elements: 1 2 3 4 5 0 0
    Size of vector v1 after resizing = 7
    */



    /*
    Static vs Dynamic Allocation :
    - Static Allocation (e.g., arrays) requires the size to be known at compile-time and cannot be changed during runtime.
    - Dynamic Allocation (e.g., vectors) allows the size to be changed during runtime, providing flexibility to accommodate varying amounts of data.
    - Vectors automatically manage memory, growing and shrinking as needed, while arrays have a fixed size once declared.
    - Vectors provide built-in functions for easy manipulation, while arrays require manual handling of memory and size.
    - Vectors can store any data type using templates, while arrays are typically of a single data type.
    - Overall, vectors are more versatile and easier to use for dynamic data storage compared to static arrays.


    Size and Capacity of Vectors :
    - Size: The number of elements currently stored in the vector (can be obtained using size() function).
    - Capacity: The amount of memory allocated for the vector, which may be larger than the current size to accommodate future growth without frequent reallocations (can be obtained using capacity() function).
    - When elements are added beyond the current capacity, the vector automatically resizes itself, typically by doubling its capacity to optimize performance.
    - How it works:
        1. Initially, a vector has a certain capacity (e.g., 0 or a small number).
        2. When elements are added using push_back(), if the size exceeds the current capacity, the vector allocates a new block of memory with larger capacity (usually double the previous capacity).
        3. The existing elements are copied to the new memory block, and the old memory is deallocated.
        4. This process continues as more elements are added, allowing the vector to grow dynamically while minimizing the number of reallocations needed.  

        Example:
        vector<int> vec;    
        cout << "Initial size: " << vec.size() << ", capacity: " << vec.capacity() << "\n";
        for(int i = 1; i <= 10; i++){
            vec.push_back(i);
            cout << "After adding " << i << ": size = " << vec.size() << ", capacity = " << vec.capacity() << "\n";
        }

        
        Output :
        Initial size: 0, capacity: 0
        After adding 1: size = 1, capacity = 1
        After adding 2: size = 2, capacity = 2
        After adding 3: size = 3, capacity = 4
        After adding 4: size = 4, capacity = 4
        After adding 5: size = 5, capacity = 8
        After adding 6: size = 6, capacity = 8
        After adding 7: size = 7, capacity = 8
        After adding 8: size = 8, capacity = 8
        After adding 9: size = 9, capacity = 16
        After adding 10: size = 10, capacity = 16





    // Pass by Reference vs Pass by Value in vectors :
    - Pass by Value: When a vector is passed by value to a function, a copy of the entire vector is made. Any modifications made to the vector inside the function do not affect the original vector outside the function. This can be inefficient for large vectors due to the overhead of copying.
    - Pass by Reference: When a vector is passed by reference (using &), no copy is made. Instead, the function operates directly on the original vector. Any modifications made to the vector inside the function will affect the original vector outside the function. This is more efficient for large vectors as it avoids the overhead of copying.
    - Example:
        void modifyVectorByValue(vector<int> vec){
            vec.push_back(100); // Modifies the copy
        }

        void modifyVectorByReference(vector<int> &vec){  // Note the '&' (ampersand) symbol indicating pass by reference 
            vec.push_back(200); // Modifies the original vector
        }

        int main(){
            vector<int> myVec = {1,2,3};

            modifyVectorByValue(myVec); // myVec remains {1,2,3}

            modifyVectorByReference(myVec); // myVec becomes {1,2,3,200}
        }
        
        Output :
        myVec after modifyVectorByValue: 1 2 3
        myVec after modifyVectorByReference: 1 2 3 200



    
    */





    // Single Number : Leetcode Problem 136 (Easy) using Vectors :
    // Problem Statement : Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    // You must implement a solution with a linear runtime complexity O(n) and use only constant extra space.

    vector<int> nums = {4,1,2,1,2}; 
    int singleNumber = 0;
    for(auto val : nums){
        singleNumber ^= val; // XOR operation to find the single number 
    }
    cout << "\nThe single number in the array is: " << singleNumber << "\n";


    /*
    Explanation:    
    - We initialize singleNumber to 0.
    - We iterate through each element in the vector nums.
    - We use the XOR operator (^) to combine each element with singleNumber.
    - Since x ^ x = 0 for any integer x, all numbers that appear twice will cancel each other out, leaving only the single number.
    - Finally, we print the single number found in the array.

    Learnings: 
    1. n^n = 0 (for any integer n) -> Same numbers cancel out to 0 when XORed
    2. n^0 = n (for any integer n) -> Any number XORed with 0 remains unchanged
    3. XOR operation is commutative and associative, allowing us to combine numbers in any order.



    Output :
    The single number in the array is: 4
    */

    



    // Linear Search in a Vector :
    vector<int> vecSearch = {10,20,30,40,50};
    int target = 30;
    for(auto val : vecSearch){
        if (val == target){
            cout << "\nElement " << target << " found in the vector.\n";
            break;
        }
    }
    



    // Reversing a Vector (2 pointer approach) :

    vector<int> rv = {10,20,30,40,50};
    cout << "\nOriginal Vector : ";
    for(auto val : rv){
        cout << val << " ";
    }

    reverseVector(rv); // Calling the reverse function

    cout << "\nReversed Vector : ";
    for(auto val : rv){
        cout << val << " ";
    } 



    return 0;
}
