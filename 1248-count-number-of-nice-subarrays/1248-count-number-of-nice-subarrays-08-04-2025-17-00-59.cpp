class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res=0;
        int i=0,j=0;
        int count=0;
        int resSubarray=0;
         while(i<nums.size()){
            if(nums[i]%2==1) count++;
            if(count ==k) resSubarray=0;
            while(count==k && j<=i){
                resSubarray++;
                if(nums[j]&1)count--;
                j++;
            }
            res+=resSubarray;
            i++;
         }
         return res;
    }
};