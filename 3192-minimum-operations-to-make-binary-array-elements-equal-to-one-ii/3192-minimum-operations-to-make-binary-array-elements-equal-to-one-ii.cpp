class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        int res=0;

        for(int i=0;i<n;i++){
           if(nums[i]==0 && res%2==0 || nums[i]==1 && res%2==1 ) res++;
        }
        return res;
    }
};