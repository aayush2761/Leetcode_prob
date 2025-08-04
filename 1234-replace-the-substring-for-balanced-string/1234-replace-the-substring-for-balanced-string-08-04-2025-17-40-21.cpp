class Solution {
public:
    int balancedString(string s) {
        // was asked substring not a subsequence 
        int total = s.size()/4;
        map<char,int>mp;
         for(auto &it : s) mp[it]++;
        //  int req=0;
         map<char,int>required;
         for(auto &it : mp){
            if(it.second>total) {
                int x= it.second-total;
               required[it.first]=x;
            }
         }
         if(required.empty()) return 0;
         map<char,int>temp;
         int ans=s.size();
         for(int i=0,j=0;i<s.size();i++){
            temp[s[i]]++;
            while(check(temp, required)){
                ans= min(ans, i-j+1);
                temp[s[j]]--;
                if(temp[s[j]]==0) temp.erase(s[j]);
                j++;
            }
         }
         return ans;
        //  return 0;
    }
    bool check(map<char, int>& window, map<char, int>& required) {
        for (auto &[ch, cnt] : required) {
            if (window[ch] < cnt)
                return false;
        }
        return true;
    }
};