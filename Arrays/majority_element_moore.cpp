#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
Brute Force Approach to find Majority Element
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
int majorityElement(vector<int> &vec, int n){
    // Pick each element one by one
    for (auto i : vec){
        int freq = 0;

        // Count frequency of current element
        for(auto j : vec){
            if(i == j){
                freq++;
            } 
        }

        // If frequency is more than n/2, it's the majority element
        if(freq > n/2){
            return i;
        }
    }
    // If no majority element exists
    return -1;
}



/*
Sorting Approach to find Majority Element
Time Complexity: O(n log n)
Space Complexity: O(1) (ignoring sort stack)
*/
int sortingApproach(vector <int> nums){
    // Sort the array
    sort(nums.begin(), nums.end());
    
    int freq = 1;               // Frequency counter
    int ans = nums[0];          // Current candidate
    int n = nums.size();        // Size of array

    // Traverse sorted array
    for(int i = 1; i < nums.size(); i++){
        // If same element continues, increase frequency
        if (nums[i] == nums[i-1]){
            freq++;
        }else{
            // New element found, reset frequency
            freq = 1;
            ans = nums[i];
        }

        // If frequency exceeds n/2, return answer
        if(freq > n/2){
            return ans;
        }
    }
    // Return candidate (majority element guaranteed in problem statement)
    return ans;
}



/*
Moore's Voting Algorithm
Time Complexity: O(n)
Space Complexity: O(1)
*/
int mooreVotingAlgo(vector<int> &vc){
    int count = 0;  // Counter for current candidate
    int ans = 0;    // Potential majority element

    // First pass: Find potential candidate
    for(int i = 0; i < vc.size(); i++){
        // If count becomes zero, pick new candidate
        if(count == 0){
            ans = vc[i];
        }

        // Increase or decrease count
        if(ans == vc[i]){
            count++;
        }else{
            count--;
        }
    }

    // Second pass: Verify if candidate is actually majority
    int freq = 0;
    for(auto val : vc){
        if(val == ans){
            freq++;
        }
    }

    // Check if frequency is greater than n/2
    if(freq > vc.size()/2){
        return ans;
    }else{
        return -1;
    }
    

    /*
    Variation : Return -1 if there is no majority element
    (This part is unreachable due to return above)
    */
    int f = 0;
    for(auto val : vc){
        if(val == ans){
            f++;
        }
    }
    if(f > vc.size()/2){
        return ans;
    }else{
        return -1;
    }
}



int main(){

/*
    // Two Sum Problem (Commented Code)

    vector<int> v = {2, 7, 11, 15};
    int target, currSum = 0;
    cout << "Enter target sum = ";
    cin >> target;
*/

/*
    // Brute Force Two Sum
    // Time Complexity: O(n^2)

    for(auto i : v){
        for(auto j : v){
            if(i != j && (i + j) == target){
                cout << i << " + " << j << " = " << target << "\n";
                return 0;
            }
        }
    }
    cout << "No such pair exist!";
*/

/*
    // Two Pointer Approach (Only works for sorted arrays)
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    int i = 0, j = v.size()-1, pairSum;
    while(i < j){
        pairSum = v[i] + v[j];

        if(pairSum > target){
            j--;    // Sum too large → move right pointer left
        }else if(pairSum < target){
            i++;    // Sum too small → move left pointer right
        }else{
            cout << v[i] << " + " << v[j] << " = " << target;
            break;
        }
    }
*/


    // Majority Element Problem
    // Element occurring more than floor(n/2) times

    // Brute Force Approach
    vector <int> vec = {2,2,1,1,1,2,2,3,3,3,3,3,3,3,3};
    int n = vec.size();
    int result = majorityElement(vec, n);

    if(result == -1){
        cout << "No majority element exist\n";
    } else {
        cout << "Majority Element in vec array : " << result << "\n";
    }


    // Sorting Approach
    vector <int> nums = {2,2,1,1,1,2,2,2,2,2,2,3,3,3,3};
    cout << "Majority Element in nums array : " << sortingApproach(nums) << "\n";


    // Moore's Voting Algorithm (Best Approach)
    vector <int> vc = {2,2,1,1,1,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,4,4};
    cout << "Majority Element in vc array : " << mooreVotingAlgo(vc) << "\n";


    /*
    How Moore's Voting Algorithm works:
    1. Initialize count = 0 and ans as candidate.
    2. Traverse the array:
       - If count == 0, choose current element as candidate.
       - If element == candidate, increment count.
       - Else decrement count.
    3. Candidate remains if majority exists.
    4. Verify candidate by counting occurrences.
    */

    return 0;
}
