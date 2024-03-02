
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int temp = 0;
        for (int i = 0; i < spaces.size(); i++) {
            res += s.substr(temp, spaces[i] - temp) + " ";
            temp = spaces[i];
        }
        res += s.substr(temp);
        return res;
    }
};
