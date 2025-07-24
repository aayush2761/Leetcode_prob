class Solution {
public:
    bool isAnagram(string s, string t) {
        int i=0,j=0;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s.size()!= t.size()) return 0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else return 0;
        }
        return 1;
    }
};