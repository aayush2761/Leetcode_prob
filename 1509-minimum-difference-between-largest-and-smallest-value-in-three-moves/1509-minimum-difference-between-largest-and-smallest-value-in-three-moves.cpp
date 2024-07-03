class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2 || n==3) return 0;
        sort(nums.begin(),nums.end());
        int tback= nums[n-4];
        int tfront= nums[3];
        return min((tback-nums[0]) , (nums[n-1]-tfront) );
         
    }
};