class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v =  heights;
        sort(heights.begin(), heights.end());
        int res=0;
        for(int i=0;i<heights.size();i++){
            if(v[i]!=heights[i]) res+=1;
        }
        return res;
    }
};