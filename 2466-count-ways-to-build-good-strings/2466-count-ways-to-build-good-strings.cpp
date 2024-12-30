class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    vector<long long> dp;

    int solve(int low, int high, int zero, int one, int len) {
        if (len > high) return 0;
        
        if (dp[len] != -1) return dp[len];

        int count = 0;
        if (len >= low && len <= high) count = 1;

        count = (count + solve(low, high, zero, one, len + zero)) % mod;
        count = (count + solve(low, high, zero, one, len + one)) % mod;
        
        return dp[len] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high + 1, -1);
        return solve(low, high, zero, one, 0);
    }
};
