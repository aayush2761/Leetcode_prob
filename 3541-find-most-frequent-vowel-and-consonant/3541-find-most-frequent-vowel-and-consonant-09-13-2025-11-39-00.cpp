class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>mp;
        for(auto &it : s) mp[it]++;
        set<char>st={'a','e','i','o','u'};
        int v=0,c=0;
        for(auto &it : mp){
            if(st.count(it.first)) v= max(v, it.second);
            else c= max(c, it.second);
        }
        return v+c;
    }
};