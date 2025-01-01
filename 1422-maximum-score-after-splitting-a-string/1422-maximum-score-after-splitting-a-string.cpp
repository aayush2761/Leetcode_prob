class Solution {
public:
    int maxScore(string s) {
        int right = 0, left = 0, res = 0;
        for (char c : s) {
            if (c == '1') right++;
        }
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') left++;
            else right--;
            res = max(res, left + right);
        }
        return res;
    }
};
