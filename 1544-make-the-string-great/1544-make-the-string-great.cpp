class Solution {
public:
    string makeGood(string s) {
        int e = s.size();
        if (e <= 1) return s;

        stack<char> st;
        st.push(s[0]);

        for (int i = 1; i < e; i++) {
            if (!st.empty() && abs(st.top() - s[i]) == 32) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string temp = "";
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};