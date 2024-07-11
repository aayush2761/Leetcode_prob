
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st; // Stack to keep track of parentheses
        stack<string> str; // Stack to store strings within parentheses
        string res = "";
        int i = 0;
        
        while (i < s.size()) {
            if (s[i] == '(') {
                st.push('('); 
                str.push(res); 
                res = ""; 
                i++;
            }
            else if (s[i] == ')') {
                reverse(res.begin(), res.end()); 
                res = str.top() + res; 
                str.pop();
                st.pop(); 
                i++;
            }
            else {
                res += s[i]; 
                i++;
            }
        }
        return res;
    }
};

