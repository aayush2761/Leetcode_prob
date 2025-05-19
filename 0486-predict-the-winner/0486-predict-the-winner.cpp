class Solution {
public:
    bool predictTheWinner(vector<int>& piles) {
         // dp[i][j]-> it states that i, j array size is remainingand out of which what i can get 
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0)); 
        vector<int>pref(n+1,0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + piles[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = piles[i];
                } else {
                    int takeLeft = piles[i] + (pref[j + 1] - pref[i + 1]) - dp[i + 1][j];
                    int takeRight = piles[j] + (pref[j] - pref[i]) - dp[i][j - 1];
                    dp[i][j] = max(takeLeft, takeRight);
                }
            }
        }

        int total = accumulate(piles.begin(), piles.end(), 0);
        return dp[0][n - 1] * 2 >= total;
    }
};