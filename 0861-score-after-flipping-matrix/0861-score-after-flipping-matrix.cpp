#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int value(vector<int> &temp)
    {
        int n = temp.size();
        int val = 1;
        int ans = 0;

        for(int i = n-1 ; i >= 0 ; i--)
        {
            int bit = temp[i];

            ans += (bit * val);

            val = (val << 1);
        }

        return ans;
    }
   int matrixScore(vector<vector<int>>& grid) {
    int n= grid.size();
    int m= grid[0].size();
    
    // Ensure each row starts with 1 by flipping if needed
    for(int i=0;i<n;i++){
        if(grid[i][0]==0){
            for(int j=0;j<m;j++){
                grid[i][j]= 1^grid[i][j];
            }
        }
    }

    // Ensure each column has more ones than zeros by flipping if needed
    for(int i=0;i<m;i++){
        int zeros = 0 , ones = 0;
        for(int row = 0 ; row < n ; row++)
        {
            if(grid[row][i] == 0)
            {
                zeros++;
            }
            else
            {
                ones++;
            }
        }
        if(zeros > ones){
            for(int j=0;j<n;j++){
                grid[j][i]= 1^grid[j][i];
            }
        }
    }
    
    // Calculate the final result by summing up values of each row
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        ans += value(grid[i]); // Compute binary to decimal value of the row
    }

    return ans;
}
};