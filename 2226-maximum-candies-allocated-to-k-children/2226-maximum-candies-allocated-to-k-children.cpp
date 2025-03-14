class Solution {
public:
    bool check(int mid, vector<int>&nums,long long k){
       long long children_count = 0;

            for (int pile : nums) {
                children_count += pile / mid;
            }

            if (children_count >= k)return true;
        return false;
    }
    int maximumCandies(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        int low=1, high=*max_element(nums.begin(), nums.end());
        int res=0;
        while(low<=high){
            int mid = low + (high-low) /2;
            if(check(mid,nums,k)){
                res=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return res;
    }
};