class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto i: s) mp[i]++;
        int res=0;
        int odd=0;
        for(auto i : mp){
            if(i.second%2==0) res+= i.second;
            else{
                res+= i.second-1;
                odd++;
            }
        }
        if(odd>0) res+=1;
        return res;
    }
};