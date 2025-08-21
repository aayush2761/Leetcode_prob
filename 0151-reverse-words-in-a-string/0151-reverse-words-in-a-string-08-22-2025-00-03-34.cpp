#include <stack>
#include <string>

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i = 0;
        while (i < s.size()) {
            // Skip spaces
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            if (i >= s.size()) break; 
            
            int j = i;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            string word = s.substr(i, j - i);
            st.push(word);
            i = j; 
        }
        
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty()) {
                res += ' '; // Add space between words
            }
        }
        
        return res;
    }
};
