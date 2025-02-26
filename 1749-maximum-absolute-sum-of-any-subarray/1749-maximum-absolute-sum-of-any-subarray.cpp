class Solution {
public:
    int maxkadane(vector<int>&nums){
        int temp=0;
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            temp+=nums[i];
            res=max(res,temp);
            if(temp<0){
                temp=0;
            }
        }
        return res;

    }
    int minkadane(vector<int>&nums){
        int temp=0;
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            temp+=nums[i];
            res=min(res,temp);
            if(temp>0){
                temp=0;
            }
        }
        return res;

    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = maxkadane(nums);
        int mini = minkadane(nums);
        return max(maxi, abs(mini));
    }
};