class Solution {
public:
    unordered_map<char,int>mp;
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n<k)return false;
        mp.clear();
        for(auto i : s)mp[i]++;
        int count=0;
        for(auto i : mp){
            if(i.second%2)count++;
        }
        if(count>k)return false;
        return true;
    // hint copy paste dont know :/
    }
};