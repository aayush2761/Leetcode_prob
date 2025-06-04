class Solution {
public:
    int directions[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int row, int col,vector<vector<int>>& grid,vector<vector<int>>& visited,int &count ){
        if(row<0 || row>=grid.size() || col<0 || col >=grid[0].size() || grid[row][col]==0) return;
        count+=1;
        // cout<<count<<endl;
        visited[row][col]=1;
        for(auto &dir : directions){
            int nrow= row+ dir[0];
            int ncol= col+ dir[1];
            if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size()){
                    if(!visited[nrow][ncol] && grid[nrow][ncol] == 1)dfs(nrow, ncol, grid, visited, count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int answer=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int count=0;
                    dfs(i,j,grid,visited,count);
                    answer=max(answer,count);
                }
            }
        }
        return answer;

    }
};