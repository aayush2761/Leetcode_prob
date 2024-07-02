class Solution {
public:
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int iniColor= image[sr][sc];
        dfs(image,ans,sr,sc,iniColor , color);
        return ans;
    }
private: 
  vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& image ,vector<vector<int>>&ans ,int sr, int sc,int iniColor, int color ){
        ans[sr][sc]=color;
        int n = image.size();
        int m = image[0].size();
        for(auto &dir : directions ){
            int row= sr + dir[0];
            int col= sc + dir[1];
             if (row >= 0 && row < n && 
                col >= 0 && col < m && 
                image[row][col]==iniColor &&
                ans[row][col] !=color
                ){
                    dfs(image,ans,row,col,iniColor, color);
                }
        }



    }
};