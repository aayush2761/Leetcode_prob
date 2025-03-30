class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;
        int res=0;
        int i=0;
        while(i<s.size()){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
               
            }
            else{
                res++;
                st.clear();
                st.insert(s[i]);

            }
             i++;
            
        }
        if(st.size()>0) res++;
        return res;
    }
};