class Solution {
public:
    int direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, vector<vector<bool>>&vis, int n, int m){
        vis[i][j]= true;
        for(auto &it : direction){
            int nx= i + it[0];
            int ny= j + it[1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid1[nx][ny]==1){
                dfs(grid1, grid2,nx,ny,vis,n,m);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int res=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1 && grid1[i][j]==1){
                    res++;
                     dfs(grid1, grid2,i,j,vis,n,m);
                }
            }
        }
        return res;
    }
};