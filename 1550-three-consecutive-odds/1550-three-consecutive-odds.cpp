class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& nums) {
        int n = nums.size();
         if(n<3) return 0;
         for(int i=2;i<n;i++){
            if((nums[i]&1) && (nums[i-1]&1) && (nums[i-2]&1))return 1;
            // else return 0;

         }
         return 0;
    }
};