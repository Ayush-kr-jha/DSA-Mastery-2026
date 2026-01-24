#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// -------------------------
// Kadane's Algorithm: Maximum Subarray Sum
// -------------------------
int maxSubarraySum(const vector<int> &v){
    int maxSum = INT_MIN;  // Handles all negative numbers
    int currSum = 0;

    for(auto i : v){
        currSum += i;
        maxSum = max(maxSum, currSum);
        if(currSum < 0) currSum = 0;
    }

    return maxSum;
}

int main(){
    vector<int> v = {-1, 2, 3, 4, -5};

    cout << "Array elements: ";
    for(auto val : v) cout << val << " ";
    cout << "\n";

    int maxSum = maxSubarraySum(v);
    cout << "Maximum Subarray Sum = " << maxSum << "\n";

    // Expected Output: 9 (2 + 3 + 4)
    /*
    How Kadane's Algorithm works:
    1. Initialize maxSum to INT_MIN and currSum to 0.
    2. Iterate through each element:
       - Add element to currSum
       - Update maxSum if currSum > maxSum
       - Reset currSum to 0 if it becomes negative
    3. maxSum contains the largest sum of any contiguous subarray.
    4. Works for all negative arrays too: maxSum = largest element.
    */

    return 0;
}
