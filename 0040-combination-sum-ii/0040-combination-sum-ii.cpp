class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> res;
         int sum = 0;
         int i = 0;
         vector<int> vec;
         sort(candidates.begin(), candidates.end());
         combinationSumHelper(i, candidates, target, sum, vec, res);
         return res;
    }
private:
    void combinationSumHelper(int i, vector<int>& candidates, int target, int sum, vector<int>& vec, vector<vector<int>>& res) {
        // base case
        if (sum == target) {
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
            combinationSumHelper(i + 1, candidates, target, sum + candidates[i], vec, res);  // correct sum update
            vec.pop_back();
        }

        // not pick
        // skip duplicates
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        combinationSumHelper(i + 1, candidates, target, sum, vec, res);
    }
};
