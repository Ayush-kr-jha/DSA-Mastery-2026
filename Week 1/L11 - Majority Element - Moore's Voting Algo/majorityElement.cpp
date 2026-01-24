#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int majorityElement(vector<int> &vec, int n){
    for (auto i : vec){
        int freq = 0;
        for(auto j : vec){
            if(i == j){
                freq++;
            } 
        }
        if(freq>n/2){
            return i;
        }
    }
    return -1;
}




int sortingApproach(vector <int> nums){
    sort(nums.begin(), nums.end()); // sorting
    
    int freq = 1, ans = nums[0], n = nums.size();

    for(int i = 1; i < nums.size(); i++){
        if (nums[i] == nums[i-1]){
            freq++;
        }else{
            freq = 1;
            ans = nums[i];
        }

        if(freq > n/2){
            return ans;
        }
    }
    return ans;
}




int mooreVotingAlgo(vector<int> &vc){
    int count = 0, ans = 0;
    for(int i = 0; i<vc.size(); i++){
        if(count == 0){
            ans = vc[i];
        }
        if(ans == vc[i]){
            count++;
        }else{
            count--;
        }
    }
    int freq = 0;
    for(auto val : vc){
        if(val == ans){
            freq++;
        }
    }

    if(freq > vc.size()/2){
        return ans;
    }else{
        return -1;
    }
    


    // Variation : Return -1 if there is no majority element : 

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

//    vector<int> v = {2, 7, 11, 15};
//    int target, currSum = 0;
//    cout << "Enter target sum = ";
//    cin >> target;
    
/*


// Time Complexity : O(n)

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

// 2 Pointer Approach : ( b'coz it is for sorted array)-> starting element will be the least and the ending element will be maximum

    int i = 0, j = v.size()-1, pairSum;
    while(i<j){
        pairSum = v[i] + v[j];
        if(pairSum > target){
            j--; // sum too big → move right pointer left
        }else if(pairSum < target){
            i++; // sum too small → move left pointer right
        }else if(pairSum == target){ // pairSum == target
            cout << v[i] << " + " << v[j] << " = " << target;
            break;
        }
    }


    // Time: O(n),  Space: O(1)

*/







    // Majority Element Problem : Find the Majority Element that occurs more than N/2 times (floor division, i.e, 9/2 = 4.5 -> 4(only integer part))

    // Bruteforce Approach : 
    vector <int> vec = {2,2,1,1,1,2,2,3,3,3,3,3,3,3,3};
    int n = vec.size();
    int result = majorityElement(vec, n);
    if(result == -1){
        cout << "No majority element exist\n";
    } else {
        cout << "Majority Element in vec array : " << result << "\n";
    }





    // Better Approach - Sorting :
    vector <int> nums = {2,2,1,1,1,2,2,2,2,2,2,3,3,3,3};
    cout << "Majority Element in nums array : " << sortingApproach(nums) << "\n";


    // Time: O(n log n) => (n of loop) + (nlogn of sorting) = O(nlogn)
    // Space: O(1) (ignoring sort stack)
    




    // Best Approach -  Moore's Voting Algorithm :
    // Time: O(n)
    // Space: O(1)
    vector <int> vc = {2,2,1,1,1,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,4,4};
    cout << "Majority Element in vc array : " << mooreVotingAlgo(vc) << "\n";
    // Time: O(n)
    
/*
How it works:
1. Initialize two variables: count (to keep track of the count of the current candidate) and ans (to store the current candidate for majority element).
2. Iterate through each element in the array:
   - If count is 0, set ans to the current element (this means we are choosing a new candidate).
   - If the current element is equal to ans, increment count.
   - Otherwise, decrement count.    
3. After the first pass, ans will hold a candidate for the majority element.
4. To confirm that ans is indeed the majority element, we need to count its occurrences in the array.
5. If the count of ans is greater than n/2, return ans as the majority element; otherwise, return -1 indicating no majority element exists.


*/


    
    return 0;
}
