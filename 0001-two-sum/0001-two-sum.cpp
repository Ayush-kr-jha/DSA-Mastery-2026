class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i+1; j < nums.size(); j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};


        // Approach 2 : Unordered Map -> TC & SC : O(n)
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            if(mpp.find(comp) != mpp.end()){
                return {i,mpp[comp]};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
    
};