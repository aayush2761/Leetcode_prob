
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int size = 0;
        while (i < s.size()) {
            int p = j;
            while (p < i) {
                if (s[i] == s[p]) {
                    j = p + 1;
                    break;
                }
                p++;
            }
            size = max(size, i - j + 1);
            i++;
        }
        return size;
    }
};
