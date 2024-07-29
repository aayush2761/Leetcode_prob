class Solution {
public:
    // Recursive function to find the longest subsequence with a given difference
    int solve(vector<int>& arr, int d, int ind, int prev, vector<vector<int>>& dp) {

        if (ind >= arr.size()) {
            return 0;
        }
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int nonPick = solve(arr, d, ind + 1, prev, dp);
        int pick = 0;
        if (prev == -1 || arr[ind] - arr[prev] == d) {
            pick = 1 + solve(arr, d, ind + 1, ind, dp);
        }

     
        return dp[ind][prev+1] = max(pick, nonPick);
    }

   
    int longestSubsequence(vector<int>& arr, int d) {
        int n = arr.size();
        if (arr.empty()) return 0;

    
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

      
        return solve(arr, d, 0, -1, dp);
    }
};
