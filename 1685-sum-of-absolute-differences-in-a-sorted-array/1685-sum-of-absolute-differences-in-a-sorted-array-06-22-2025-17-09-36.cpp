class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return {0};
        vector<int>leftSum(n,0), rightSum(n,0);
        leftSum[0]= nums[0];
        for(int i=1;i<n;i++){
            leftSum[i]= leftSum[i-1] + nums[i];
        }
        rightSum[n-1]= nums[n-1];
        for(int i=n-2;i>=0;i--){
            rightSum[i]= rightSum[i+1] + nums[i];
        }
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int lsize= i, rSize=n-i-1;
            if(i==0)res[i]= rightSum[i+1]- nums[i]*rSize;
            else if (i==n-1) res[i]= nums[i]*lsize - leftSum[i-1];
            else {
                res[i]= abs(nums[i]*lsize- leftSum[i-1])+ (rightSum[i+1]- nums[i]*rSize);
            }
        }
        return res;
    }
};