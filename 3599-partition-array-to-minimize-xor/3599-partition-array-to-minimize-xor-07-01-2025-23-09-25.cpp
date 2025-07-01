class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int  n = nums.size();
        vector<vector<int>>dp(n,vector<int>(k,INT_MAX));
        // final subproblem 
        dp[0][0]= nums[0];
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]^ nums[i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<k;j++){
                // // pick condition 
                // int pick = dp[i-1][j]^nums[i];
                // int notPick= nums[i];
                // dp[i][j]= min(pick,notPick);
                int xr = nums[i];

                for (int it = i - 1; it >= 0; --it) {
                    int mx = max(dp[it][j - 1], xr);
                    dp[i][j] = min(dp[i][j], mx);
                    xr ^= nums[it];  // build XOR from right to left
                }
            }
        }
        return dp[n-1][k-1];
    }
};