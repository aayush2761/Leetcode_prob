class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int n = s.size();
        vector<vector<char>> v(numRows, vector<char>(n, '0'));

        bool goingDown = true;
        int index = 0;
        int i = 0, j = 0;

        while (index < n) {
            v[i][j] = s[index];
            index++;

            if (goingDown) {
                if (i == numRows - 1) {
                    goingDown = false;
                    i--;
                    j++;
                } else {
                    i++;
                }
            } else {
                if (i == 0) {
                    goingDown = true;
                    i++;
                } else {
                    i--;
                    j++;
                }
            }
        }

        string res = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] != '0') {
                    res.push_back(v[i][j]);
                }
            }
        }
        return res;
    }
};
