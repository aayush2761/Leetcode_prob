class Solution {
public:
    int maximumRobbing(vector<int>& nums,int index,vector<int>& dp){
        if(index==0) return nums[index];
        if(index<0) return 0;
        //check if previously present 
        if(dp[index]!=-1) return dp[index];
        //check for pick and non pick
        int pick=  nums[index]+ maximumRobbing(nums, index-2,dp);
        int notPick = 0+ maximumRobbing(nums, index-1, dp);

        // return maximum to that index 
        return dp[index]= max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1 , -1);
       return  maximumRobbing(nums, nums.size()-1, dp);

       
    }
};