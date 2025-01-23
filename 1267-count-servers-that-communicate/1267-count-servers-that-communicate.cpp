class Solution {
public:
    int n,m;
    unordered_map<int,int> row,col;
    int countServers(vector<vector<int>>& arr) 
    {
        n=arr.size();
        m=arr[0].size();
        int ans=0;
        // unordered_map<int,int> row,col;
        row.clear();
        col.clear();
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
            {
                if(arr[r][c]==1)
                {
                    row[r]++;
                    col[c]++;
                }
            }
        }
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
            {
                if(arr[r][c]==1 && (row[r]>=2 || col[c]>=2)) ans++;
            }
        }
        return ans;
    }
};