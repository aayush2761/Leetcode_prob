class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int,int>>vp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                vp[mat[i][j]]={i,j};
            }
        }
        //
        unordered_map<int,int>row;
         for(int i=0;i<mat.size();i++){
            row[i]=mat[0].size();
         }
         unordered_map<int,int>col;
         for(int i=0;i<mat[0].size();i++){
            col[i]=mat.size();
         }

        for(int i=0;i<arr.size();i++){
            int a,b;
            auto it = vp[arr[i]];
            a=it.first;
            b= it.second;
            row[a]--;
            col[b]--;
            if(row[a]==0 || col[b]==0){
                return i;
            }
        }
        return -1;

    }
};