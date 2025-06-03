class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (isPalindrome(s, i, j))
                    ++count;
            }
        }
        return count;
    }
    
private:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
};
