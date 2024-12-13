class Solution {
public:
    string rabinKarp(string s, int power, int mod, int k, int hashValue) {
        int n = s.size();
        long long hashs = 0, powerK = 1;
        string res = "";
        for (int i = 0; i < k - 1; i++) {
            powerK = (powerK * power) % mod;
        }
        
        for (int i = n - 1, j = n - k; i >= 0; i--) {
            hashs = (hashs * power + (s[i] - 'a' + 1)) % mod;
            if (i + k <= n) {  
                if (hashs == hashValue) {
                    res = s.substr(i, k);
                }
                hashs = (hashs - (s[i + k - 1] - 'a' + 1) * powerK % mod + mod) % mod;
            }
        }
        return res;
    }
// inverse rabinKarb 
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        return rabinKarp(s, power, mod, k, hashValue);
    }
};
