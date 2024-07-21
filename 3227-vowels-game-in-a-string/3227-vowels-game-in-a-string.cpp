class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                mp[s[i]] = i;
            }
        }
        // remove
        if (mp.size() % 2 != 0)
            return true;
        if (mp.size() == 1)
            return true;
        if (mp.size() == 0)
            return false;
        if (mp.size() % 2 == 0)
            return true;
        else
            return false;
    }
    // private:
    //     int solve(string s , bool parity){
    //         int t=0;
    //         // party->odd
    //         // parity not -> even
    //         if(parity){
    //             for(int i=0;i<s.size();i++){

    //             }
    //         }
    //     }
};