class Solution {
public:
    int direction [4][2]={{0,-1},{0,1},{1,0},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) {q.push({i,j}); vis[i][j] = 1;}
            }
        }
        int count=0;
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){
                // mark visited 
                auto it = q.front();
                q.pop();
                if(mat[it.first][it.second]==0) dist[it.first][it.second]=0;
                else dist[it.first][it.second]=count;
                // vis[it.first][it.second]=1;
                for(auto dir : direction){
                    int nX = it.first+ dir[0];
                    int nY = it.second+ dir[1];
                    if(nX>=0 && nX<n && nY>=0 && nY<m && vis[nX][nY]==-1) {q.push({nX, nY});vis[nX][nY]=1;}
                }
            }
            count++;
        }
        return dist;

    }
};