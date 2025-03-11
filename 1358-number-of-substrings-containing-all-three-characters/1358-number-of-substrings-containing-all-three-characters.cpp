class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int res=0;
        int i=0,j=0;
        while(i<s.size()){
            mp[s[i]]++;
            while(mp.size()==3){
                res+=s.size()-i;
                mp[s[j]]--;
                if(mp[s[j]]==0)mp.erase(s[j]);
                j++;
            }
            i++;
        }
        return res;
    }
};