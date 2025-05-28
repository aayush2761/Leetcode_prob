class Solution {
public:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int row= moveTime.size();
        int col= moveTime[0].size();
        vector<vector<int>>resultTime(row,vector<int>(col,INT_MAX));
        // time -> position(row,col)
        queue<pair<int,pair<int,int>>>dijkstrasQueue;
        dijkstrasQueue.push({0,{0,0}});
        resultTime[0][0]=0;
        while(!dijkstrasQueue.empty()){
            auto topElement = dijkstrasQueue.front();
            dijkstrasQueue.pop();
            // top_element 
           for(auto &dir: directions){
                 int newRow= topElement.second.first + dir[0];
                int newCol= topElement.second.second +  dir[1];
                if(newRow>=0 && newRow<row && newCol>=0 && newCol<col){
                    int currentTime = 1 + topElement.first;
                    int gridValue= 1+moveTime[newRow][newCol];
                    if(max(currentTime,gridValue)< resultTime[newRow][newCol]){
                        resultTime[newRow][newCol]=max(currentTime,gridValue);
                        dijkstrasQueue.push({resultTime[newRow][newCol],{newRow,newCol}});
                    }
                }
           }
        }
        return resultTime[row-1][col-1];
    }
};