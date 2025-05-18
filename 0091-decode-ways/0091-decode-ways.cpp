class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        if(s[0]=='0')return 0;
        //  dp[i]-> number of ways to decode the string from n to ith positon ;
        vector<int>dp(n+1,0);
       dp[n] = 1;  // Base case: empty string
        dp[n - 1] = (s[n - 1] != '0') ? 1 : 0;
        for(int i=n-2;i>=0;i--){
           if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                int num = stoi(s.substr(i, 2));
                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};