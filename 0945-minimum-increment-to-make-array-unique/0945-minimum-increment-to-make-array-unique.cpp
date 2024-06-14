class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
               int increment = nums[i - 1] - nums[i] + 1; // calculate the necessary increment
                nums[i] += increment; // increment the current element
                res += increment;
            }
        }
        return res;
    }
};