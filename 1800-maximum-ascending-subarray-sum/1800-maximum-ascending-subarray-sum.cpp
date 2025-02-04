class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res=0;
        int i=0;
        int temp=nums[0];
        res=max(res,temp);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                temp+=nums[i];
            }
            else temp=nums[i];
            res=max(res,temp);
        }
        return res;
    }
};