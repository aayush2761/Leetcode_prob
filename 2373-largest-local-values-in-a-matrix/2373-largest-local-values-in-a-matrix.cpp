// class Solution {
// public:
// //checker function 
//     int largestInMatrix(vector<vector<int>> v){
//         int temp=INT_MIN;
//         for(int i=0;i<v.size();i++){
//             for(int j=0;j<v[0].size();j++){
//                 if(temp<v[i][j]) temp=v[i][j];
//             }
//         }
//          return temp;
//     }
//     vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
//         int n= grid.size();
//         vector<vector<int>>resultMatrix;
//         // 3*3 grid 
//         for(int i = 0 ; i < n-2 ; i++)
//         {
//             vector<vector<int>> temp;
//             vector<int>level;
//             for(int j = 0 ; j < n-2 ; j++)
//             {
//                 temp.push_back( {grid[i][j] , grid[i][j+1] , grid[i][j+2]});
//                 temp.push_back( {grid[i+1][j] , grid[i+1][j+1] , grid[i+1][j+2]});
//                 temp.push_back( {grid[i+2][j] , grid[i+2][j+1] , grid[i+2][j+2]});

//               level.push_back(largestInMatrix(temp));
//             }
            
//             resultMatrix.push_back(level );
          
//         }
//         return     resultMatrix;
//     }
// };

