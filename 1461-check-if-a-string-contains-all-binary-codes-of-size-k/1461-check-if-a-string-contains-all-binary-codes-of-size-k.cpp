class Solution {
public:
    vector<int> z; // Public vector to avoid memory reallocation

    bool zTheorem(string &s, int rr) {
        int n = s.size();
        z.assign(n, 0); // Reset the Z array to size n with all elements 0
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
            if (z[i] == rr) return true;
        }
        return false;
    }
    bool rabinKarp(string s, string pattern) {
    int n = s.size(), m = pattern.size();
    if (n < m) return false;

    long long hashs = 0, hashp = 0, power = 1;
    const int mod = 1e9 + 7;

    // Precompute hash for the pattern and initial window in the string
    for (int i = 0; i < m; i++) {
        hashp = (hashp * 31 + (pattern[i] - '0')) % mod;
        hashs = (hashs * 31 + (s[i] - '0')) % mod;
        if (i > 0) power = (power * 31) % mod; 
    }
    for (int i = m; i <= n; i++) {
        if (hashs == hashp) return true; 
        if (i < n) {
            hashs = (hashs * 31 + (s[i] - '0')) % mod; // Add next char
            hashs = (hashs - (s[i - m] - '0') * power % mod + mod) % mod; // Remove first char
        }
    }

    return false;
}
    bool hasAllCodes(string s, int k) {
    //    if (s.size() < k) return false;

    //     int totalCodes = 1 << k; // 2^k binary codes
    //     for (int i = 0; i < totalCodes; ++i) {
    //         string pattern = bitset<20>(i).to_string().substr(20 - k, k);
    //         if (!rabinKarp(s, pattern)) return false;
    //     }

    //     return true;
    int n = s.size(); 
	unordered_set<string> set;
	for(int i = 0; i <= n - k; i++) 
		set.insert(s.substr(i, k)); // distinct substrings of size k
	return set.size() == (1 << k);
    }
};
