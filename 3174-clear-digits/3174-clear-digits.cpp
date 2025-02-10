class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (i > 0) {
                    s.erase(i-1, 2);
                    n = s.size(); 
                    i--; 
                } else {
                    s.erase(i, 1);
                    n = s.size(); 
                }
            } else {
                i++;
            }
        }
        return s;
    }
};