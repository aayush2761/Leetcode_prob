class Solution {
public:
    bool isValid(std::string s) {
       stack<int>st;
       for(int i=0;i<s.size();i++){
           if(s[i]=='[' || s[i]=='{' || s[i]=='('){
               st.push(s[i]);
           }
           else{
               if(st.empty()) return false;
               char c=st.top();
               st.pop();
               if(s[i]==')' && c=='(') continue;
               else if(s[i]=='}' && c=='{') continue;
               else if(s[i]==']' && c=='[') continue;
               else{
                   return false;
               }
           }
       }
       if(st.empty()) return true;
       return false;
    }
};
