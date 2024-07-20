class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>res(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp= min(rowSum[i],colSum[j]);
                res[i][j]=temp;
                // sub from row;
                rowSum[i]-=temp;
                colSum[j]-=temp;
            }
        }
        return res;
    }
};