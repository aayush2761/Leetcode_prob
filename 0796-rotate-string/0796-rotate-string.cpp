class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!= goal.size()) return false;
        int n=s.size();
        while(n--){
            char temp= s[0];
            s.erase(0,1);
            s.push_back(temp);
            if(s==goal) return true;
        }
        return false;
    }
};