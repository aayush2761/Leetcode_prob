// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int mp[26]={0};
//         int t[26]={0};
//         for(int i=0;i<s2.size();i++) mp[s2[i]-'a']++;
//         for(int i=0,j=0;j<s1.size();j++){
//            t[s1[j]-'a']++;
//            if(j-i+1==s2.size()){
//             bool flag=false;
//               for(int k=0;k<26;k++){
//                 if(t[k]!=mp[k]){
//                     flag=true;
//                     break;
//                 }
//               }
//               if(!flag) return true;
//               t[s1[i]-'a']--;
//               i++;
//            }
//         }
//         return false;
//     }
// };
#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size())
            return false;

        std::vector<int> mp(26, 0);
        std::vector<int> t(26, 0);

        for (char c : s1)
            mp[c - 'a']++;

        for (int i = 0; i < s2.size(); i++) {
            t[s2[i] - 'a']++;

            if (i >= s1.size()) {
                t[s2[i - s1.size()] - 'a']--;
            }

            if (t == mp)
                return true;
        }

        return false;
    }
};
