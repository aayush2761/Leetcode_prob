class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first search in column one 
        int n = matrix.size();
        int m= matrix[0].size();
        int low = 0, high = matrix.size();
        int index=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[mid][0]==target) return 1;
            else if(matrix[mid][0]<target){
                index= mid;
                low=mid+1;
            }
            else high= mid-1;
        }
        // search on  that index
        int l =0, h= m;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(matrix[index][mid]==target) return 1;
            else if(matrix[index][mid]<target){
                l= mid+1;
            }
            else h= mid-1;
        }
        return 0;
    }
};