class Solution {
public:
    int mod = 1e9 + 7;
    long dp[23][2][401];

    long solve(int index, bool tight, int currSum, int &min_sum, int &max_sum, string &s) {
        // base case 
        if (index == s.size()) {
            return currSum >= min_sum && currSum <= max_sum;
        }
        // dp !=-1
        // already calculated previously
        if (dp[index][tight][currSum] != -1) return dp[index][tight][currSum];

        long ans = 0;

        // calculate limit 
        int limit = tight ? s[index] - '0' : 9;
        for (int d = 0; d <= limit; d++) {
            int newTight = tight & (d == limit);
            ans = (ans + solve(index + 1, newTight, currSum + d, min_sum, max_sum, s)) % mod;
        }

        return dp[index][tight][currSum] = ans;

    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        // for 0 to low 
        memset(dp, -1, sizeof(dp));
        int index = 0;
        bool tight = true;
        int currSum = 0;
        long countone = solve(index, tight, currSum, min_sum, max_sum, num1);
        // for 0 to high 
        memset(dp, -1, sizeof(dp));
        // int index=0;
        // bool tight=true;
        // int currSum=0;
        long counttwo = solve(index, tight, currSum, min_sum, max_sum, num2);
        // we are cal from o to low and 0 to high 
        // we need to substract l seperately to get 0 to l-1 from currSum
        int sum = 0;
        for (auto d : num1) {
            sum += d - '0';
        }
        if (sum >= min_sum && sum <= max_sum) countone--;

        // if we consider a=100 and b=40 then a-b will be negative therefore add mod to diff and take modulo.
        return (((counttwo - countone) % mod) + mod) % mod;
    }
};
