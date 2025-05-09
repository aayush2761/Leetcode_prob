class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // take the hint it is nice way 
        // state ->>>> dp[i] maximum partioned sum from o to ith index 
        int n = arr.size();
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
             int maxi = 0;
            for (int x = 1; x <= k && i - x >= 0; x++) {
                maxi = max(maxi, arr[i - x]);
                dp[i] = max(dp[i], dp[i - x] + maxi * x);
            }
        }
        return dp[n];
    }
};