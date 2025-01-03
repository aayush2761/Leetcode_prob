class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            // Check for odd-length palindromes
            string temp = "";
            temp += s[i];
            int left = i - 1, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                temp = s[left] + temp + s[right];
                left--;
                right++;
            }
            if (temp.size() > res.size()) res = temp;

            // Check for even-length palindromes
            temp = "";
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                temp = s[left] + temp + s[right];
                left--;
                right++;
            }
            if (temp.size() > res.size()) res = temp;
        }
        return res;
    }
};
