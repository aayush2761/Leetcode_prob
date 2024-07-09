class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>start= nums;
        res.push_back(start);
        next_permutation(start.begin(),start.end());
        vector<int>st=start;
        while(st!=nums){
            res.push_back(st);
            next_permutation(st.begin(),st.end());
        }
        return res;
    }
};