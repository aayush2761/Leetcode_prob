class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       
        // sort each 
        for(int i=0;i<n;i++){
            sort(grid[i].begin(),grid[i].end());

        }
        // check 
        int res=0;
        for(int i=0;i<m;i++){
             priority_queue<int>pq;
            for(int j=0;j<n;j++){
                pq.push(grid[j][i]);
            }
            res+= pq.top();
            //pq.clear();
        }
        return res;
    }
};