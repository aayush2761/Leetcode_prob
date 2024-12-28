class Solution {
public:
    vector<int> dp = vector<int>(10001, INT_MAX); 
    vector<int> perfectSquare;

    void precompute() {
        for (int i = 1; i * i <= 10000; i++) {
            perfectSquare.push_back(i * i);
        }
        dp[0] = 0;

        for (int i = 1; i <= 10000; i++) {
            for (int j = 0; j < perfectSquare.size() && perfectSquare[j] <= i; j++) {
                dp[i] = min(dp[i], dp[i - perfectSquare[j]] + 1);
            }
        }
    }

    int numSquares(int n) {
        if (dp[1] == INT_MAX) precompute(); 
        return dp[n];
    }
};
