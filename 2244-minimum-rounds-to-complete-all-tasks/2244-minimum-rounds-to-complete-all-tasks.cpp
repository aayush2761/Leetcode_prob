class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int res=0;
        unordered_map<int,int>mp;
        for(auto &it : tasks)mp[it]++;
        for(auto it = mp.begin(); it != mp.end();it++){
            if(it->second==1) return -1;
            res+= it->second/3;
            if(it->second%3!=0) res++;
        }
        return res;
    }
};