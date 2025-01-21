class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum=accumulate(grid[0].begin(),grid[0].end(),0LL);;
        int n = grid[0].size();
        if(n<2) return 0;
        // code 
        long long res=LONG_MAX;
        long long bottomSum=0;
        for(int i=0;i<n;++i){
            topSum-=grid[0][i];
            res=min(res,max(topSum,bottomSum));
             bottomSum += grid[1][i];
        }
        return res;
    }
};



// class Solution {
// public:
//     long long gridGame(vector<vector<int>>& grid) {
//         int i=0,j=0;
//         int n= grid[0].size()-1;
//         //robot 1 
//         while(i<2){
//             while(j<=n){
//                 grid[i][j]=0;
//                 //down 
//                 if(i==0 && j==1) j++;
//                 // right corner 
//                 else if(i==0 && j==grid[0].size()-1) i++; 
//                 //break condition 
//                 if (i==1 && j== grid[0].size()-1) break;

//                 if(grid[i][j+1]>grid[i+1][j]) i++;
//                 else j++;


//             }
//              break;
//         }
//         //robot 2 
//         int answer=0;
//         i=0,j=0; while(i<2){
//             while(j<=n){
//                answer+= grid[i][j];
//                 //down 
//                 if(i==0 && j==1) j++;
//                 // right corner 
//                 else if(i==0 && j== grid[0].size()-1) i++; 
//                 //break condition 
//                 if (i==1 && j== grid[0].size()-1) break;

//                 if(grid[i][j+1]<grid[i+1][j]) i++;
//                 else j++;


//             }
//             break;
//         }
//         return answer;
//     }
// };