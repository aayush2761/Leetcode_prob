class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[ edges[i][0]]++;
            mp[ edges[i][1]]++;
        }
        for(auto i :  mp){
            if(i.second==n) return i.first;
        }
        return -1;
    }
};