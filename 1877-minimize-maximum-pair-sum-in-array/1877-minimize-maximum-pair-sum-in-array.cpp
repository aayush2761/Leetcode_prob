class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        int l=0, r= nums.size()-1;
        while(l<r){
            res= max(res, nums[l]+nums[r]);
            l++;
            r--;
        }
        return res;
    }
};