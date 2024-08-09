class Solution {
public:
    // index tight oddcount evencount remainder validNum 
    int dp[10][2][6][6][20][2];

    long solve(int index, bool tight, int oddCount, int evenCount, int remainder, bool validNum, int k, string &s) {
        // base case 
        if (index >= s.size()) {
            return (oddCount == evenCount) && (remainder == 0);
        }
        // pruning 
        if ((oddCount > 5) || (evenCount > 5)) return 0;

        if (dp[index][tight][oddCount][evenCount][remainder][validNum] != -1) 
            return dp[index][tight][oddCount][evenCount][remainder][validNum];

        int ans = 0;

        // calculate limit 
        int limit = tight ? s[index] - '0' : 9;
        for (int d = 0; d <= limit; d++) {
            int newTight = tight & (d == limit);

            // leading zero 
            if (validNum == false && d == 0) 
                ans += solve(index + 1, newTight, oddCount, evenCount, remainder, false, k, s);
            else if (d % 2 == 0)  
                ans += solve(index + 1, newTight, oddCount, evenCount + 1, (remainder * 10 + d) % k, true, k, s);
            else  
                ans += solve(index + 1, newTight, oddCount + 1, evenCount, (remainder * 10 + d) % k, true, k, s);
        }

        return dp[index][tight][oddCount][evenCount][remainder][validNum] = ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp, -1, sizeof(dp));
        string l = to_string(low - 1);
        string h = to_string(high);
        int index = 0;
        bool tight = true;
        int currSum = 0;
        int oddCount = 0;
        int evenCount = 0;
        bool validNum = false;
        int remainder = 0;
        long countone = solve(index, tight, oddCount, evenCount, remainder, validNum, k, l);

        // for 0 to high 
        memset(dp, -1, sizeof(dp));
        long counttwo = solve(index, tight, oddCount, evenCount, remainder, validNum, k, h);

        // if we consider a=100 and b=40 then a-b will be negative therefore add mod to diff and take modulo.
        return counttwo - countone;
    }
};
