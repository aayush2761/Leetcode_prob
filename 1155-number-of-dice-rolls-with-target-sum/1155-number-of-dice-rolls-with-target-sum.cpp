class Solution {
public:
    const int mod = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        // dp[i][t]-> number of ways to achieve sum t using i dices 
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        // for(int i=0;i<=n;i++) dp[i][0]=1;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                for(int f=1;f<=k;f++){
                    if(j>=f){
                        dp[i][j]= (dp[i][j] % mod +  dp[i-1][j-f] % mod)%mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};