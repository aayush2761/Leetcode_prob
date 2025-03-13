class Solution {
public:
    vector<int>diff;
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        diff.assign(n + 1, 0);
        int i=0;
        while(i<queries.size()){
            int left = queries[i][0];
            int right = queries[i][1]+1;
            int val = 1;
            diff[left]+=val;
            diff[right]-=val;
            i++;
        }
        // //  diff
        for(int i=1;i<=n;i++){
            diff[i]+=diff[i-1];
        }
        for(int i=0;i<n;i++){
            // nums[i]+=diff[i];   -> do not modify the nums 
            if(nums[i] - diff[i] > 0) return false;
        }
        return true;
    }
};



