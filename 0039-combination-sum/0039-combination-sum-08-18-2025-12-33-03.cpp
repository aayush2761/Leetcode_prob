class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int> vec;
       
        solve(0,candidates,target,vec,res);
        return res;
    }
    private:
    void solve(int i, vector<int>& candidates, int target,  vector<int> vec,vector<vector<int>>&res){
       if(i==candidates.size()){
        if(target==0) res.push_back(vec);
         return;

       }
        // pick consition 
        if(candidates[i]<=target){
            //pick 
         
            // continue picking 
            vec.push_back(candidates[i]);
            solve(i,candidates,target-candidates[i],vec,res);
            // remove also after reaching end 
            vec.pop_back();
        }
        // not pick 
        solve(i+1,candidates,target,vec,res);

    }
};