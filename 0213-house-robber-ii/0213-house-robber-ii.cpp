class Solution {
public:
    int robbingHouse(vector<int>& nums){
          vector<int>dp(nums.size(), -1);
         dp[0]=nums[0];
        if(nums.size()>1)
            {
                dp[1] = max(nums[0], nums[1]);
            }
      for(int i=2; i<nums.size();i++){

        int pick= nums[i]+ dp[i-2];
        int notPick= 0+ dp[i-1];
        dp[i]= max(pick,notPick);
      }

       return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>a1;
        vector<int>a2;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(i!=0) a1.push_back(nums[i]);
            if(i!=n-1) a2.push_back(nums[i]);
        }
        return max(robbingHouse(a1),robbingHouse(a2));
    }
};