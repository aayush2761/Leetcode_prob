class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        stack<int>st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='(') st.push('(');
            else {
                if(!st.empty() && st.top()=='(') st.pop();
                else cnt++;
            }
            i++;
        }
        return cnt+ st.size();
    }
};