class Solution {
public:
    int minimumLength(string s) {
        int  n = s.size();
        if(n<3) return n;
        unordered_map<char,int>mp;
        for(auto i : s) mp[i]++; 

        int res=0;
        for(auto i : mp){
            if(i.second<3) res+= i.second;
            else if(i.second%2==0) res+=2;
            else res+= 1;
        }
        return res;
    }
};