class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n<original.size())return {};
        int row= original.size()/n;
        int col=n;
        vector<vector<int>>res(row,vector<int>(col,-1));
        int ind=0;
        int ri=0;
        while(ind<original.size()){
            for(int j=0;j<n;j++){
                res[ri][j]=original[ind];
                ind++;
            }
            ri++;
        }
        return res;
    }
};