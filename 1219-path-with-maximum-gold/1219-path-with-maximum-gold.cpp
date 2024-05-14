class Solution {
public:
    int n, m, ans = 0;
    vector<vector<int>>mat;
    bool visited[20][20];
    void DFS(int i, int j, int &sum, int &ans)
    {
        if(i >= n or i < 0 or j >= m or j < 0 or visited[i][j] or !mat[i][j]) 
        {
            ans = max(ans, sum);
            return;
        }

        visited[i][j] = true;
        sum += mat[i][j];

        DFS(i+1, j, sum, ans), 
        DFS(i-1, j, sum, ans), 
        DFS(i, j+1, sum, ans), 
        DFS(i, j-1, sum, ans);

        visited[i][j] = false;
        sum -= mat[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        mat = grid, n = mat.size(), m = mat[0].size();
        int ans = 0, sum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] > 0)
                {
                    DFS(i, j, sum, ans);
                    sum = 0;
                }
            }
        }
        return ans;
    }
};