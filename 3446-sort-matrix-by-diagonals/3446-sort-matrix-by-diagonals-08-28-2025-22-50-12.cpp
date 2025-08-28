class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,vector<int>>mp;
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>res(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        // sort
        for(auto &it : mp){
             if (it.first >= 0) {
                // bottom-left triangle (including main diagonal)
                sort(it.second.rbegin(), it.second.rend()); // non-increasing
            } else {
                // top-right triangle
                sort(it.second.begin(), it.second.end());   // non-decreasing
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         res[i][j] = mp[i-j].back();
        //         mp[i-j].pop_back();
        //     }
        // }
         // Track positions in each diagonal
        unordered_map<int,int> pos;

        // Fill result matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                res[i][j] = mp[key][pos[key]++];
            }
        }
        return res;

    }
};