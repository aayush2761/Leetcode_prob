class Solution {
public:
    int largest2pow(int n) {
        int ret = 0, temp = 1;
        while (temp <= n) {
            ret++;
            temp <<= 1;
        }
        return ret;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const unsigned MOD = 1e9+7, maxpow = largest2pow(t);
        //char, charmap, time
        vector<vector<vector<long>>> dp(26, vector<vector<long>>(26, vector<long>(maxpow, 0)));
        vector<int> count(26), newcount(26);
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j < nums[i]+1; j++) {
                dp[i][(i+j)%26][0]++;
            }
        }
        for (int i = 1; i < maxpow; i++) {
            for (int j = 0; j < 26; j++) { //current char
                for (int k = 0; k < 26; k++) { //char mapping
                    if (!dp[j][k][i-1]) continue;
                    for (int l = 0; l < 26; l++) { //find new chars
                        dp[j][l][i] = (dp[j][l][i] + (dp[k][l][i-1]*dp[j][k][i-1])%MOD) % MOD;
                    }
                }
            }   
        }
        for (int i = 0; i < s.length(); i++) {
            count[s[i]-'a']++;
        }
        int temp = pow(2, 30), c = 30;
        while (t != 0) {
            if (temp & t) {
                for (int i = 0; i < 26; i++) {
                    if (!count[i]) continue;
                    for (int j = 0; j < 26; j++) {
                        newcount[j] = (newcount[j] + (dp[i][j][c]*count[i]) % MOD) % MOD;
                    }
                }
                count = newcount;
                fill(newcount.begin(), newcount.end(), 0);
                t -= temp;
            }
            temp >>= 1;
            c--;
        }
        for (int i = 0; i < 26; i++) {
            ans = (ans + count[i]) % MOD;
        }
        return ans;
    }
}; 