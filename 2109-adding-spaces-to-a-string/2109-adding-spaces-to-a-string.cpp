class Solution {
public:
    string addSpaces(string s, vector<int>& v) {
        string res = "";
        int i = 0, index = 0, prev = 0;
        
        while (index < v.size()) {
            string p = s.substr(i, v[index] - prev);
            res += p + ' ';
            i += v[index] - prev;
            prev = v[index];
            index++;
        }
        
        res += s.substr(i);
        return res;
    }
};
