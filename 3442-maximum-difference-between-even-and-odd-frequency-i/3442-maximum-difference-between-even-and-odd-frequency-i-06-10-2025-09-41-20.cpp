class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        for(auto &it : s)mp[it]++;
        int maxi=0, mini=INT_MAX;
        for(auto & it  : mp){
            if(it.second&1){
                maxi=max(maxi,it.second);
            }
            else {
                mini=min(mini,it.second);
            }
        }
        // base case is that it constains altleast one even and odd so good to go 
        return maxi-mini;
    }
};