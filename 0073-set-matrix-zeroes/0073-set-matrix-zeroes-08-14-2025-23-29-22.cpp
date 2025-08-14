class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        // vector<int>rows, cols;
        set<int>row, col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    // rows.push_back(i);
                    // cols.push_back(j);
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        // setZeros 
        for(auto &it : row){
            int row=it;
            // int col=it;
            for(int i=0;i<m;i++){
                matrix[row][i]=0;
            }
            // for(int i=0;i<n;i++){
            //     matrix[i][col]=0;
            // }
        }
        for(auto &it : col){
            int col=it;
            // // int col=it;
            // for(int i=0;i<m;i++){
            //     matrix[row][i]=0;
            // }
            for(int i=0;i<n;i++){
                matrix[i][it]=0;
            }
        }
        
    }
};