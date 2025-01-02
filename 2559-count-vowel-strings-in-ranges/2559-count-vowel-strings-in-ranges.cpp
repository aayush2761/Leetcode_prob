class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>count(n,0);
        unordered_set<char>st{'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            int first = words[i][0];
            int last = words[i][words[i].size()-1];
            if(st.find(first)!=st.end() && st.find(last)!=st.end())count[i]=1;
            // else count
        }
        vector<int>pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+count[i-1];
        }
        // answer queries 
        int m = queries.size();
        vector<int>res(m);
        for(int i=0;i<m;i++){
            int left = queries[i][0];
            int right = queries[i][1]+1;
            res[i]=pref[right]-pref[left];
        }
        count.clear();
        return res;
    }
};