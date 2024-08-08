class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         int total = accumulate(nums.begin(),nums.end(),0);
        int pref=0;
        for(int i=0;i<nums.size();i++){
            if(i>0)pref+= nums[i-1];
            int suff= total - pref- nums[i];
            if(suff==pref) return i;
        }
        return -1;
    }
};