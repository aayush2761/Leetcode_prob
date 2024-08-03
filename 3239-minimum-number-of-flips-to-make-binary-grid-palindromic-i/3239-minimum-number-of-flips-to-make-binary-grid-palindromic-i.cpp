class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int res=0;
        int n= grid.size();
        int m = grid[0].size();
        int row=0,col=0;
        for(int i=0;i<n;i++){
            // consider row 
            int p=0,q= m-1;
            while(p<=q){
                if(grid[i][p]!=grid[i][q]) row++;
                p++;
                q--;
            }
        }
        for(int i=0;i<m;i++){
            // consider row 
            int p=0,q= n-1;
            while(p<=q){
                if(grid[p][i]!=grid[q][i]) col++;
                p++;
                q--;
            }
        }
        return min(row,col);
    }
};