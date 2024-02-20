class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
       // sort(nums.begin(),nums.end());
        while(n>0){
           ans^=nums[n-1]^n;
           n--;
        }
        return ans;
        
    }
};