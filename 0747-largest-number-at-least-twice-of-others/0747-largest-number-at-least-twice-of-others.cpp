class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int>v(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int n = nums.size();
        bool flag=false;
        int temp=-1;
        if(nums[n-1]>= 2*nums[n-2]) {
            flag=true;
            
        }
        if(flag){
            // find the index
            for(int i=0;i<n;i++){
                if(v[i]==nums[n-1]) return i;
            }
        }
        return -1;
    }
};