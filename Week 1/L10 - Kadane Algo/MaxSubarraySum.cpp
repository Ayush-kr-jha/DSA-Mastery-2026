#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int maxSubarraySum(vector<int> &v, int sz){
    int maxSum = INT_MIN, currSum = 0;
    for( auto i : v){
        currSum += i;
        maxSum = max(maxSum, currSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    return maxSum;
}

int main(){
    vector<int> v = {-1, 2, 3, 4, -5};
    int sz = v.size();
    cout << maxSubarraySum(v, sz);

    // Expected Output: 9 (2 + 3 + 4)
    // Explanation: The contiguous subarray with the largest sum is [2, 3, 4], which sums to 9.
    /*
    How kadane Algorithm works here:
    1. Initialize maxSum to the smallest integer value and currSum to 0.    
    2. Iterate through each element in the array:
       - Add the current element to currSum.
       - Update maxSum if currSum is greater than maxSum.
       - If currSum becomes negative, reset it to 0.
    3. After iterating through the array, maxSum will hold the maximum subarray sum.
    4. Return maxSum.

    if array is entirely negative, maxSum will be the largest (least negative : -1) element.
    To handle this case, we can modify the algorithm to check for all negative numbers and return the maximum element in that scenario.
    
    */

    return 0;
} 
