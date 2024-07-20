// class Solution {
// public:
//     vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
//         vector<int>col(colsum.begin(),colsum.end());
//        vector<int>rowSum={upper,lower};
//         int m = colsum.size();
//         vector<vector<int>>res(2,vector<int>(m,0));

//         for(int i=0;i<2;i++){
//             for(int j=0;j<m;j++){
//                 int temp=0;
//                 temp= min( rowSum[i],colsum[j]);
//                 if(temp>=1){
//                     res[i][j]=1;
                    
//                      if( rowSum[i]>=1)  rowSum[i]-=1;
//                     if( colsum[j]>=1)  colsum[j]-=1;
//                 }

               
//             }
//         }
//         // check the col sum 
//         for(int j=0;j<m;j++){
//             int temp=0;
//             for(int i=0;i<2;i++){
//                 temp+=res[i][j];
//             }
//             if(temp!= col[j]) return {};
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<int> col(colsum.begin(), colsum.end());
        vector<int> rowSum = {upper, lower};
        int m = colsum.size();
        vector<vector<int>> res(2, vector<int>(m, 0));

        // First pass: Allocate 2's to both rows
        for (int j = 0; j < m; ++j) {
            if (colsum[j] == 2) {
                if (rowSum[0] > 0 && rowSum[1] > 0) {
                    res[0][j] = 1;
                    res[1][j] = 1;
                    rowSum[0]--;
                    rowSum[1]--;
                } else {
                    return {}; // Impossible to allocate
                }
            }
        }

        // Second pass: Allocate 1's to either row
        for (int j = 0; j < m; ++j) {
            if (colsum[j] == 1) {
                if (rowSum[0] > 0) {
                    res[0][j] = 1;
                    rowSum[0]--;
                } else if (rowSum[1] > 0) {
                    res[1][j] = 1;
                    rowSum[1]--;
                } else {
                    return {}; // Impossible to allocate
                }
            }
        }

        // Final check for column sums
        for (int j = 0; j < m; ++j) {
            int temp = 0;
            for (int i = 0; i < 2; ++i) {
                temp += res[i][j];
            }
            if (temp != col[j]) return {}; // Check against original column sums
        }

        // Final check for row sums
        if (rowSum[0] != 0 || rowSum[1] != 0) {
            return {}; // Impossible to match the given row sums
        }

        return res;
    }
};
