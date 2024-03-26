class Solution {
public:
    vector<int> arrayChange(vector<int>& v, vector<vector<int>>& p) {
        unordered_map<int,int>mp;
        for(int i=0;i<v.size();i++)mp[v[i]]=i;
        for(auto i:p){
            v[mp[i[0]]]=i[1];
            mp[i[1]]=mp[i[0]];
        }
        return v;

    }
};