class Solution {
public:
    void solve(vector<vector<int>>&res, vector<int>&temp, vector<int>&nums){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            // return;
        }
        else{
            for(int i=0;i<nums.size();i++){
                if(find(temp.begin(), temp.end(), nums[i])!= temp.end()) continue;
                // put 
                temp.push_back(nums[i]);
                solve(res, temp, nums);
                // back track 
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(res, temp, nums);
        return res;
    }
};