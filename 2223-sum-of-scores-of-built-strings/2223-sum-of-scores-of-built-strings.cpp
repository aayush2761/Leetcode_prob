class Solution {
public:
    void zTheorem(string s, vector<int>& z) {
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]); // Corrected logic
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
    }

    long long sumScores(string s) {
        int n = s.size();
        vector<int> z1(n, 0);
        zTheorem(s, z1);
        long long res = 0;
        for (int i = 0; i < n; i++) { // Fixed loop to include the last index
            res += z1[i];
        }
        return res + n; // Add the length of the string
    }
};
