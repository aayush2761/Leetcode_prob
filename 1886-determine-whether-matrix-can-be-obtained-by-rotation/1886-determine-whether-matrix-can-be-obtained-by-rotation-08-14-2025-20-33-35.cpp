class Solution {
public:
    bool a90Degree(vector<vector<int>> mat, vector<vector<int>>& target){
        reverse(mat.begin(), mat.end());
        for(int i=0;i<mat.size();i++){
            for(int j= i+1;j<mat[0].size();j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        return mat==target;
    }
    bool a180Degree(vector<vector<int>> mat, vector<vector<int>>& target){
        reverse(mat.begin(), mat.end());
        for(int i=0;i<mat.size();i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        return mat==target;
    }
    bool a270Degree(vector<vector<int>> mat, vector<vector<int>>& target){
         for(int i=0;i<mat.size();i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        for(int i=0;i<mat.size();i++){
            for(int j= i+1;j<mat[0].size();j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
         return mat==target;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // reverse col and then transpose 
        if (mat == target) return true; 
        if(a270Degree(mat, target)) return true;
        if(a180Degree(mat, target)) return true;
        if(a90Degree(mat, target)) return true;
        // if(a90Degree(mat, target)) return true;
        // if(a90Degree(mat, target)) return true;
        return false;
    }
};