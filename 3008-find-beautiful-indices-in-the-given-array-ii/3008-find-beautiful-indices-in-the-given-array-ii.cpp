class Solution {
public:
    const int mod = 1e9 + 7;
    void rollingHash(string &s, string &pattern, vector<int> &valid) {
        long long patternHash = 0, hash = 0;
        int p = 31; 
        long long power = 1;
        for (int i = 0; i < pattern.size(); i++) {
            patternHash = (patternHash * p + (pattern[i] - 'a' + 1)) % mod;
            if (i > 0) power = (power * p) % mod;
        }
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            hash = (hash * p + (s[i] - 'a' + 1)) % mod;
            if (i - j + 1 == pattern.size()) {
                if (hash == patternHash) valid.push_back(j);
                hash = (hash - (s[j] - 'a' + 1) * power % mod + mod) % mod;
                j++;
            }
        }
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        // Use rolling hash to find valid indices
        vector<int> valida, validb;
        rollingHash(s, a, valida);
        rollingHash(s, b, validb);
        vector<int> res;
        int i = 0, j = 0;
        while (i < valida.size() && j < validb.size()) {
            if (abs(valida[i] - validb[j]) <= k) {
                res.push_back(valida[i]);
                i++;
            } else if (valida[i] < validb[j]) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};
