class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        string r1,r2;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                r1.push_back(s1[i]);
                r2.push_back(s2[i]);
            }
        }
        if(r1.size()==2 && r1[0]==r2[1] && r1[1]==r2[0]) return true;
        return false;
    }
};