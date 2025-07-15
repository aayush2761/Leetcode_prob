class Solution {
public:
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        // make directed graph with the wt as effort 
        // star node 0,0
        // end node n,m 
        // bellman can be used 
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(m,-1));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        dist[0][0]=0;
        pq.push({0,0,0});//-> min ,i,j
        while(!pq.empty()){
            auto vec = pq.top();
            int val = vec[0];
            int i = vec[1];
            int j = vec[2];
            pq.pop();

            if(vis[i][j]==1)continue;
            vis[i][j]=1;
            for(auto &it : dir){
                int ni= i+it[0];
                int nj= j+it[1];
                if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                    int nval = max(val, abs(heights[i][j] - heights[ni][nj]));
                    if (dist[ni][nj] > nval) {
                        dist[ni][nj] = nval; 
                        pq.push({nval, ni, nj});
                    }
                }
            }
        }
        if(dist[n-1][m-1]==INT_MAX) return -1;
        return dist[n-1][m-1];
    }
};