#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------
// Bruteforce Approach (O(n^2))
// -------------------------
int majorityElementBruteforce(const vector<int> &vec){
    int n = vec.size();
    for (auto i : vec){
        int freq = 0;
        for (auto j : vec){
            if(i == j) freq++;
        }
        if(freq > n/2) return i;
    }
    return -1;
}

// -------------------------
// Sorting Approach (O(n log n))
// -------------------------
int majorityElementSorting(vector<int> nums){
    sort(nums.begin(), nums.end()); // Sort the array
    int freq = 1, n = nums.size(), ans = nums[0];

    for(int i = 1; i < n; i++){
        if(nums[i] == nums[i-1]){
            freq++;
        } else {
            freq = 1;
            ans = nums[i];
        }
        if(freq > n/2) return ans;
    }
    return ans;
}

// -------------------------
// Moore's Voting Algorithm (O(n))
// -------------------------
int majorityElementMoore(const vector<int> &vc){
    int count = 0, candidate = 0;

    // Step 1: Find candidate
    for(auto val : vc){
        if(count == 0){
            candidate = val;
        }
        count += (val == candidate) ? 1 : -1;
    }

    // Step 2: Verify candidate
    int freq = 0;
    for(auto val : vc){
        if(val == candidate) freq++;
    }

    return (freq > vc.size()/2) ? candidate : -1;
}

int main(){
    // Test arrays
    vector<int> vec1 = {2,2,1,1,1,2,2,3,3,3,3,3,3,3,3};
    vector<int> vec2 = {2,2,1,1,1,2,2,2,2,2,2,3,3,3,3};
    vector<int> vec3 = {2,2,1,1,1,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,4,4};

    cout << "Bruteforce Approach: ";
    int res1 = majorityElementBruteforce(vec1);
    cout << (res1 == -1 ? "No majority element" : to_string(res1)) << "\n";

    cout << "Sorting Approach: " << majorityElementSorting(vec2) << "\n";

    cout << "Moore's Voting Algorithm: " << majorityElementMoore(vec3) << "\n";

    /*
    Explanation:
    - Bruteforce: Counts frequency of each element.
    - Sorting: Sorts array; consecutive duplicates are counted.
    - Moore's Voting: Picks a candidate in O(n) time, then verifies.
    */

    return 0;
}
