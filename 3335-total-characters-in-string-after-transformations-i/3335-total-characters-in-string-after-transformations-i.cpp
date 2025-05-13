#define mod 1000000007
class Solution {
public:
    //  unordered_map<char,int>temp;
    int lengthAfterTransformations(string s, int t) {
        // unordered_map<char,int>mp;
        vector<int>mp(26,0);
        for(auto it : s)mp[it-'a']++;
        while (t--) {
            // unordered_map<char, int> temp;
            // temp.clear();
            vector<int>temp(26,0);
            for (int i=0;i<26;i++) {
                if (i==25) {
                    temp[0] = (temp[0] + mp[i]) % mod;
                    temp[1] = (temp[1] + mp[i]) % mod;
                } else {
                    temp[i+1] = (temp[i+1] + mp[i]) % mod;
                }
            }
            mp = (temp);
        }
        int res=0;
         for(auto it : mp){
            res= (res+ it)%mod;
         }
         return res;
    }
};