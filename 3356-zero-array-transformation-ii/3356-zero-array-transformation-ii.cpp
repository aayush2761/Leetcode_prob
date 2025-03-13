class Solution {
public:
    vector<int>diff;
    bool check(int mid , vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        diff.assign(n + 1, 0);
        int i=0;
        while(i<mid){
            int left = queries[i][0];
            int right = queries[i][1]+1;
            int val = queries[i][2];
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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // Decrement the value at each index in the range [li, ri] in nums by at most vali.
        // first k queries
        // bs on answers or k 
        int low =0, high = queries.size();
        int res=-1;
        while(low<=high){
            int mid = low + (high-low) /2;
            if(check(mid,nums,queries)){
                res=mid;
                high = mid-1;
            }
            else low=mid+1;
        }
        return res;

    }
};