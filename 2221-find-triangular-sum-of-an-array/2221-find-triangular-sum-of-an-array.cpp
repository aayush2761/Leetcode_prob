class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>prev=nums;
        while(prev.size()>2){
            int n = prev.size()-1;
            vector<int>curr(n);
            for(int i=0;i<n;i++){
                curr[i]=(prev[i]+ prev[i+1])%10;
            }
            prev=curr;
        }
        return (prev[0]+prev[1])%10;
    }
};