class Solution {
public:
    bool doesAliceWin(string s) {
        int count=0;
        set<char>st={'a','e','i','o','u'};
        for(auto &it : s){
            if(st.count(it)) count++;

        }
        return count>0;
    }
};