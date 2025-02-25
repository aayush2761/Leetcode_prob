class Solution {
public:
    int rob(vector<int>& nums) {
       // dp state -> it store the maximum amount that can be robbed from 0 to i 
       // transition equation // pick not pick 
       // dp[i]= max(dp[i-1], nums[i]+dp[i-2]);
       // base case dp[0]=0, dp[1]= nums[0];
       int n = nums.size();
       vector<int>dp(n+1,0);
       dp[1]=nums[0];
       for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1], dp[i-2]+nums[i-1]);
       }
       return dp[n];

    }
};