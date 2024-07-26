class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>candidates={1,2,3,4,5,6,7,8,9};
        vector<int> vec;
         vector<vector<int>> res;

        combinationSumHelper(0,candidates,n,0,vec,res, k);
        return res;

    }
private:
    void combinationSumHelper(int i, vector<int>& candidates, int target, int sum, vector<int>& vec, vector<vector<int>>& res,int k) {
        // base case
        if (sum == target && vec.size()==k) {
            res.push_back(vec);
            return;
        }
        if (i == candidates.size()) {
            return;
        }

        // pick
        // only once
        if (sum + candidates[i] <= target) {  // correct sum update
            vec.push_back(candidates[i]);
            combinationSumHelper(i + 1, candidates, target, sum + candidates[i], vec, res,k);  // correct sum update
            vec.pop_back();
        }

        // not pick
        // skip duplicates
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        combinationSumHelper(i + 1, candidates, target, sum, vec, res,k);
    }
};