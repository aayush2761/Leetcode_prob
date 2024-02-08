class Solution {
public:
    int arraySign(vector<int>& nums) {
        int temp=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) nums[i]=1;
            else if(nums[i]<0) nums[i]=-1;
            else{
                return 0;
            }
        }
        for(int i=0;i<nums.size();i++){
            temp*=nums[i];
        }
        if(temp>0) return 1;
        if(temp<0) return -1;
        return 0;
    }
};