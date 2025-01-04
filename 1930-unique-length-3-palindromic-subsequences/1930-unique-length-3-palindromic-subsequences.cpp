class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> st;
        unordered_set<char> charst;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (charst.find(s[i]) != charst.end()) continue;
            charst.insert(s[i]);
            
            int j = n - 1;
            while (j > i && s[j] != s[i]) {
                j--;
            }
            
            if (s[i] == s[j]) {
                for (int k = i + 1; k < j; k++) {
                    string temp = "";
                    temp += s[i];
                    temp += s[k];
                    temp += s[j];
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};
