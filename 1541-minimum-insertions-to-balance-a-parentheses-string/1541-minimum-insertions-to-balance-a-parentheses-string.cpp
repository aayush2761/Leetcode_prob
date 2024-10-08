class Solution {
public:
    int minInsertions(string s) {
    // string modified;
    int n = s.size(), ans = 0;
    stack<char> st;

    for (int i = 0; i < n; i++) {
        // Missing an opening '('
        if (i + 1 < n && s[i] == ')' && s[i + 1] == ')' && st.empty()) {
            ans++;
            i++;
        // Matching an opening '(', so pop it
        } else if (i + 1 < n && s[i] == ')' && s[i + 1] == ')') {
            st.pop();
            i++;
        // Missing an opening '(', and a second closing ')'
        } else if (s[i] == ')' && st.empty()) {
            ans += 2;
        // Missing a second closing ')'
        } else if (s[i] == ')') {
            ans++;
            st.pop();
        // Push any opening '(' into the stack
        } else {
            st.push(s[i]);
        }
    }
    
    // st.size() is the number of opening '(' that doesn't have any matching closing ones ')'
    return ans + st.size() * 2;
}
};
