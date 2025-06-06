class Solution {
public:
    string robotWithString(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string p="", t="";
        stack<char>st;// for t
        int i=0;
        while(i<s.size()){
            while(!st.empty() && st.top()<s[i]){
                p.push_back(st.top());
                cout<<p<<endl;
                st.pop();

            }
            st.push(s[i]);
            i++;
        }
        while(!st.empty()){
                p.push_back(st.top());
                // cout<<p<<endl;
                st.pop();

        }       
       if(p.size()== rev.size() && p< rev) return p;
       return rev;
    }
};