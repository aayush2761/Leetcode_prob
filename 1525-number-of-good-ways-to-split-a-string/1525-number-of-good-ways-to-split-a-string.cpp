class Solution {
public:
    int numSplits(string s) {
        int n= s.size();
        if(n==1)return 0;
        vector<int>left(n),right(n);
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            left[i]=st.size();
        }
        // unordered_set<char>st;
        st.clear();
        for(int i=n-1;i>=0;i--){
            st.insert(s[i]);
            right[i]=st.size();
        }
        int res=0;
        for(int i=0;i<n-1;i++){
            if(left[i]==right[i+1])res++;
        }
        return res;
    }
};