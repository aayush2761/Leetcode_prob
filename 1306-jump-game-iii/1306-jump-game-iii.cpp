class Solution {
public:

    bool solve(vector<int>& arr, int n, int start, vector<bool>& visited) {
    if (start < 0 || start >= n || visited[start]) return false;
    if (arr[start] == 0) return true;
    visited[start] = true;
    return solve(arr, n, start + arr[start], visited) || 
           solve(arr, n, start - arr[start], visited);
}

    bool canReach(vector<int>& arr, int start) {
        int resIndex=-1;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]==0){
        //         resIndex=i;
        //         break;
        //     }
        // }
        int n= arr.size();
         vector<bool> visited(n,0);
        // if(resIndex==-1) return 0;
        return solve(arr,n, start,visited);
    }
};