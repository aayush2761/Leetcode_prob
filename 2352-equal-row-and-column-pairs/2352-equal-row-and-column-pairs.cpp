class Solution {
public:
    bool check(vector<int>& v1, vector<int>& v2) {
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }

    int equalPairs(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                vector<int> col;
                for(int k = 0; k < n; k++) {
                    col.push_back(grid[k][j]);
                }
                if(check(grid[i], col)) {
                    res++;
                }
            }
        }
        
        return res;
    }
};
