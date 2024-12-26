class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
         vector<int> dp(target+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=target;i++){
        for(int j=0;j<coins.size();j++){
           if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    // cout<<dp<<endl;
    return dp[target] == INT_MAX ? -1 : dp[target];
    }
};