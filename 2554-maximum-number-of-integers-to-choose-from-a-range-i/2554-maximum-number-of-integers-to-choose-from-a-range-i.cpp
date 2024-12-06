class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(auto i: banned) st.insert(i);
        // code 
        int res=0;
        int count=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)!=st.end()) continue;
            else if(i+count<=maxSum){
                count+=i;
                res++;
            }
            else break;
        }
        return res;
    }
};