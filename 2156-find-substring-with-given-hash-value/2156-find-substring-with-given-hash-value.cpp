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
                    // not returning because we need first substr

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
// Why can't we go left-to-right, and use inverse modulo to do the division? 
// The reason is that inverse modulo may not exist for a given power and modulo.
// here modulo can be such a number that co exists factor with the comnputed hash value and thus we cannot find the 
// modulo therefore right to left :) // galat hai ZZZ!!!



// https://medium.com/coding-interview-preparation/leetcode-a-rolling-hash-coding-problem-ec43d415c72c
// better explainmation why to use reverse 