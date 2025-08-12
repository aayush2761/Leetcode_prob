class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // if(nums.size()==)
        int res=nums[0];
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp+= nums[i];
            res= max(res, temp);
            if(temp<0) temp=0;

        }
        return res;
    }
};