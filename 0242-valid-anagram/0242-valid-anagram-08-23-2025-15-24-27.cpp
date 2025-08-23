class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()) return 0;
        map<int,int>mp;
        for(auto &it : s) mp[it]++;
        for(auto &it : t){
            if(mp.count(it)){
                mp[it]--;
                if(mp[it]==0) mp.erase(it);
            }
        }
        return mp.size()==0;
    }
};