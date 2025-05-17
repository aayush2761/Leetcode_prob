class Solution {
public:
    int maxArea(vector<int>& nums) {
        int res=0;
        int n = nums.size()-1;
        int left= 0, right= n;
        while(left<right){
            res= max(res, (right-left)*(min(nums[left],nums[right])));
            if(nums[left]>=nums[right])right--;
            else left++;
        }
        return res;
    }
};