class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col= matrix[0].size();
        int top=0,left=0;
        int bottom= row-1, right= col-1;
        vector<int> result;
        while(left<=right && top<=bottom){
            // right 
            for(int i=left; i<=right;i++){
                result.push_back(matrix[top][i]);
               
            }
             top++;
            //bottom 
            for(int i= top ; i<=bottom;i++){
                result.push_back(matrix[i][right]);
              
            }
              right--; 

            // left

            if(top<= bottom){
                 for(int i= right ; i>=left;i--){
                result.push_back(matrix[bottom][i]);
              
            }
              bottom--;
            }
            //top
            if(left<=right){
                 for(int i= bottom ; i>=top;i--){
                result.push_back(matrix[i][left]);
              
            }
             left++;
            }
            
        }
        return result;
    }
};