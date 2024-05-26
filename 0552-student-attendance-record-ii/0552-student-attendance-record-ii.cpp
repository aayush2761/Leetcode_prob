class Solution {
public:
    long long int mod = 1e9 + 7;
    long long int dp[100001][2][3];
    
    int helper(int n, int absent, int late){ 
        if(late >= 3 || absent >= 2) return 0; // <- not an eligible record condition 
        if(n == 0) return 1; // <- recurrence call till n == 0, i.e. we got an eligible record, yayy! 
        
        //Memoization 
        if(dp[n][absent][late] != -1) return dp[n][absent][late];
        
        //Recurrence calls
        int p_selected = helper(n-1, absent, 0); // <- if we selected Present
        int a_selected = helper(n-1, absent + 1, 0); // <- if we selected Absent
        int l_selected = helper(n-1, absent, late + 1); // <- if we selected Late
        
        // Output = Sum of all three recurrence call outputs 
        return dp[n][absent][late] = ( p_selected%mod + 
                                       a_selected%mod + 
                                       l_selected%mod )%mod;
    }
    
    int checkRecord(int n) {
        //Initializing dp with -1
        memset(dp, -1, sizeof(dp));
        return helper(n, 0, 0);
    }
};