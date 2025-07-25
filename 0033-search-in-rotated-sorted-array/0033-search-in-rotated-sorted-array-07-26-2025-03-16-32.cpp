class Solution {
public:
    int bs(int i, int j , vector<int>&nums, int target){
        while(i<=j){
            int m= i + (j-i)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>target) j= m-1;
            else i= m+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pindex=-1;
        int l= 0, h= nums.size()-1;
        while(l<h){
            int m= l + (h-l)/2;
            if(nums[m]>nums[h])l= m+1;
            else h= m;
        }
        pindex=l;
        int res;
        h= nums.size()-1;
        if(target>=nums[pindex] && target<= nums[h]){
            res= bs(pindex, h, nums,target);
        }
        else res= bs(0,pindex-1, nums,target);
        return res;
    }

};