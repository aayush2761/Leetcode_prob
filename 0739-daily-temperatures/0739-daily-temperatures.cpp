class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>>st;
        int n = t.size();
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i]=0;
                st.push({t[i],i});
            }
            else{
                while(!st.empty() && st.top().first<=t[i])st.pop();
                if(st.empty()){
                     res[i]=0;
                    st.push({t[i],i});
                }
                else{
                    auto it = st.top();
                    res[i]= it.second - i ;
                    st.push({t[i],i});
                }
            }

        }
        return res;
    }
};
