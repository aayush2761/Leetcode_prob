class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(s[i]==')'){
                    if(!st.empty() && st.top()=='(') st.pop();
                    else return 0;
                }
                else if(s[i]==']') {
                        if(!st.empty() && st.top()=='[') st.pop();
                        else return 0;
                }
                else{
                     if(!st.empty() && st.top()=='{') st.pop();
                    else return 0;
                }
            }
            i++;
        }
        return st.empty();
    }
};