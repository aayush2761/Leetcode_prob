class Solution {
public:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};    
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int answer=0;
        vector<vector<int>>visited(row, vector<int>(col,-1));
        queue<pair<int,int>>queuePositions;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0)visited[i][j]=1;
                if(grid[i][j]==2){
                    queuePositions.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        // do the bfs traversal 
      
        while(!queuePositions.empty()){
            int queueSize= queuePositions.size();
              bool affected=false;
            for(int i=0;i<queueSize;i++){
                auto it = queuePositions.front();
                queuePositions.pop();
                    int a =it.first;
                    int b =it.second;
                 
                    for(auto dir : directions){
                        int dx = dir[0];
                        int dy = dir[1];
                        if((a+dx>=0 && a+dx<row) && ( b+dy>=0 && b+dy<col)){
                            if(grid[a+dx][b+dy]==1 && visited[a+dx][b+dy]==-1){
                                grid[a+dx][b+dy]=2;
                                affected=true;
                                queuePositions.push({a+dx, b+dy});
                                   visited[a+dx][b+dy]=1;
                            }
                        }
                    }
                 
            }
               if(affected)answer++;
            
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return answer;
    }
};