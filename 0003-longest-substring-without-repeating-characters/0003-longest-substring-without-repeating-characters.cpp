class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int i=0,j=0;
        int res=0;
        while(i<s.size()){
             if(st.find(s[i])==st.end()){
                st.insert(s[i]);
                res=max((int)st.size(),res);
                i++;
                
            }
            else{
                st.erase(s[j]);
                j++;
            }
            
        }
        return res;
    }
};


// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char,int>mp;
//         int i=0,j=0;
//         int ans=0;
//         while(i<s.size()){
//             char c=s[i];
//             mp[c]++;
//             while (mp[c] > 1) {
//                 mp[s[j]]--;
//                 j++;
//             }
            
//             ans = max(ans, i - j + 1);
//             i++;
//         }
//         return ans;
//     }
// };