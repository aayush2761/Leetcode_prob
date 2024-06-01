class Solution {
public:
    int scoreOfString(string s) {
        int res= 0;
        int i=1;
        while(i<s.size()){
            res+= abs(s[i-1]-s[i]);
            i++;
        }
        return res;
    }
};