class Solution {
public:
    int count(vector<int>& nums, int maxi, int temp, int idx){
        if(idx==nums.size()){
            if(maxi==temp) return 1;
            return 0;
        }
        return count(nums, maxi, temp|nums[idx], idx+1) + count(nums,maxi, temp, idx+1);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        // The maximum bitwise-OR is the bitwise-OR of the whole array.
        int maxi =0;
        for(auto &it : nums) maxi |= it;
        int answer=0;
        return count(nums,maxi, 0, 0);
    }
};