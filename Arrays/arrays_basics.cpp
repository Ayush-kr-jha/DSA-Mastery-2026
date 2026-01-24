/*
arrays_basics.cpp
Topic: Arrays
Playlist Lecture: L8
Description: Basic array operations:
1. Linear Search (with user input)
2. Reverse Array
3. Sum & Product
4. Swap Max/Min
5. Unique Values
6. Intersection of Arrays
*/

#include <iostream>
#include <climits>
#include <utility>
using namespace std;

// -------------------------
// Linear Search
// -------------------------
int linearSearch(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target) return i;
    }
    return -1;
}

// -------------------------
// Reverse Array (2-pointer)
// -------------------------
void reverseArray(int arr[], int n){
    int start = 0, end = n-1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++; end--;
    }
}

// -------------------------
// Sum & Product of Array
// -------------------------
pair<int,int> sumProd(int arr[], int n){
    int sum = 0, prod = 1;
    for(int i=0; i<n; i++){
        sum += arr[i];
        prod *= arr[i];
    }
    return {sum, prod};
}

// -------------------------
// Swap Max & Min
// -------------------------
void swapMaxMin(int arr[], int n){
    int minVal = INT_MAX, maxVal = INT_MIN;
    int minIdx, maxIdx;
    for(int i=0; i<n; i++){
        if(arr[i] > maxVal){ maxVal = arr[i]; maxIdx = i; }
        if(arr[i] < minVal){ minVal = arr[i]; minIdx = i; }
    }
    swap(arr[minIdx], arr[maxIdx]);
}

// -------------------------
// Print Unique Values
// -------------------------
void printUnique(int arr[], int n){
    cout << "\nUnique values in the array are: ";
    for(int i=0; i<n; i++){
        bool found = false;
        for(int j=0; j<n; j++){
            if(i != j && arr[i] == arr[j]){
                found = true;
                break;
            }
        }
        if(!found) cout << arr[i] << " ";
    }
}

// -------------------------
// Intersection of Two Arrays
// -------------------------
void intersection(int arr1[], int n1, int arr2[], int n2){
    cout << "\n\nIntersection of 2 arrays is: ";
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(arr1[i] == arr2[j]){
                cout << arr1[i] << " ";
                break; // avoid duplicate printing
            }
        }
    }
}

// -------------------------
// Main Function
// -------------------------
int main(){
    int arr[] = {5,15,22,1,-15,24};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original Array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << "\n";

    // Finding Min, Max, and their indices
    int smallest = INT_MAX, largest = INT_MIN;
    int smallestIndex, largestIndex;
    for(int i=0; i<n; i++){
        if(arr[i] < smallest){ smallest = arr[i]; smallestIndex = i; }
        if(arr[i] > largest){ largest = arr[i]; largestIndex = i; }
    }

    cout << "Minimum Element: " << smallest << " at index " << smallestIndex << "\n";
    cout << "Largest Element: " << largest << " at index " << largestIndex << "\n";

    // -------------------------
    // Linear Search (User Input)
    // -------------------------
    int nums[] = {2,5,7,-2,20,32,203};
    int sz_nums = sizeof(nums)/sizeof(nums[0]);
    cout << "\nArray Elements are: ";
    for(int i=0; i<sz_nums; i++) cout << nums[i] << " ";
    
    int target;
    cout << "\nEnter target element for Linear Search: ";
    cin >> target;
    int res = linearSearch(nums, sz_nums, target);
    if(res == -1) cout << "Element not found in the array\n";
    else cout << "Element found at index = " << res << "\n";

    // -------------------------
    // Reverse Array
    // -------------------------
    int nums1[] = {2,5,6,9,2,0,-1};
    int sz1 = sizeof(nums1)/sizeof(nums1[0]);
    cout << "\nOriginal Array to Reverse: ";
    for(int i=0; i<sz1; i++) cout << nums1[i] << " ";
    
    reverseArray(nums1, sz1);
    cout << "\nReversed Array: ";
    for(int i=0; i<sz1; i++) cout << nums1[i] << " ";

    // -------------------------
    // Sum & Product
    // -------------------------
    int nums2[] = {2,5,6,9,2,-1};
    int sz2 = sizeof(nums2)/sizeof(nums2[0]);
    pair<int,int> result = sumProd(nums2, sz2);
    cout << "\n\nSum of elements of nums2 = " << result.first;
    cout << "\nProduct of elements of nums2 = " << result.second << "\n";

    // -------------------------
    // Swap Max & Min
    // -------------------------
    swapMaxMin(nums2, sz2);
    cout << "After swapping Max & Min elements of nums2: ";
    for(int i=0; i<sz2; i++) cout << nums2[i] << " ";

    // -------------------------
    // Unique Values
    // -------------------------
    int nums3[] = {2,1,2,1,3,4,5,6,2,1,2,4};
    int sz3 = sizeof(nums3)/sizeof(nums3[0]);
    printUnique(nums3, sz3);

    // -------------------------
    // Intersection
    // -------------------------
    int x[] = {1,2,3,4,5};
    int y[] = {4,5,6,7,8};
    intersection(x, sizeof(x)/sizeof(x[0]), y, sizeof(y)/sizeof(y[0]));

    return 0;
}
