class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push({s[i],1});
            }
            else{
                auto it = st.top();
                // st.pop();
                if(it.first == s[i]){
                    it.second++;
                    st.pop();
                    if(it.second < k) st.push(it); 
                }
                else {
                    st.push({s[i],1});
                }
            }
        }
        string res="";
        while(!st.empty()){
            auto x = st.top();
            st.pop();
            int n = x.second;
            while(n--){
                res+= x.first;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};