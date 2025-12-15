class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        // dp[i] -> number of smooth descent periods 
        // if the current is not smooth descent then dp[i] = 1
        // else dp[i] = dp[i-1]+1
        int n = prices.size();
        vector<int>dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(prices[i-1]==prices[i]+1) dp[i]= dp[i-1]+1;
            else dp[i]= 1;
        }
        long long ans=0LL;
        ans= accumulate(dp.begin(), dp.end(), 0LL);
        return ans;

    }
};

// 1 3 6 7
// 3 2 32 -> 21, 321, 1