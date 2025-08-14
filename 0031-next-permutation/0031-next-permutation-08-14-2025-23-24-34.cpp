class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // narayana pandit 
        int left, right;
        int n = nums.size();
        for(left=n-2;left>=0 ; left--){
            if(nums[left]<nums[left+1]) break;
        }
        if(left<0){
            reverse(nums.begin(), nums.end());
        }
        else{
            // find the right greatest 
            for(right= n-1;right>left;right--){
                if(nums[left]<nums[right]){
                    break;
                    
                }
            }
             swap(nums[left], nums[right]);
            reverse(nums.begin()+ left+1, nums.end());
        }

    }
};