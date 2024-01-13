class Solution {
public:
    int minSteps(string s, string t) {
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
           arr[s[i]-'a']++;
           arr[t[i]-'a']--;

        }
       int ans = 0;
       int  i = 0;

        while (i < 26) {
            ans += max(0, arr[i]);
            i++;
        }
        return ans;
    }
};