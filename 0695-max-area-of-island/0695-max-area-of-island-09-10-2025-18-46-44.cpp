class Solution {
public:
    int directions[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int  dfs(vector<vector<int>>&vis,vector<vector<int>>& grid, int i, int j, int n, int m ){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || vis[i][j]==1) return 0;
        vis[i][j]=1;
        int x=1;
        for(auto &dir : directions){
            // directions count
            int ni= i+ dir[0];
            int nj= j+ dir[1];

             x+=dfs(vis,grid,ni,nj,n,m);
               
        }
        return x;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1){
                    int x =0;
                    x+= dfs(vis, grid, i, j,n,m);
                    ans= max(x,ans);
                }
            }
        }
        return ans;
    }
};