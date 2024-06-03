class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        int j = 0; // pointer for string t

        for (int i = 0; i < n; ++i) {
            if (j < m && s[i] == t[j]) {
                ++j;
            }
        }

        // j now represents the length of the subsequence of t that is found in s
        return m - j;
    }
};



// "abcdefghijklmnopqrstuvwxyz"
// "zyxwvutsrqponmlkjihgfedcba"