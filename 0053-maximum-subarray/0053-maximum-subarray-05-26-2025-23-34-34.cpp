class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN, count=0;
        for(int i=0;i<nums.size();i++){
            count+=nums[i];
            ans=max(ans,count);
            if(count<=0) count=0;
        }
        return ans;
    }
};