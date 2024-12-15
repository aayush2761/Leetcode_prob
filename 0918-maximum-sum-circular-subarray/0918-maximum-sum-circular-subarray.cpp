class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        // for(int i=0;i<n;i++) nums.push_back(nums[i]);
        int sum=0;
        int maxi=INT_MIN;
        int total =0;
        int mini=0;

        // [|||||           ||||||]
        for(int i=0;i<n;i++){
            total+=nums[i];
            sum+=nums[i];
            mini=min(mini,sum);
            if(sum>0)sum=0;
        }
        sum=0;
        // [  |||||||||||||   ]
        for(int i=0;i<n;i++){
            sum+=nums[i];

            maxi=max(sum,maxi);
            if(sum<0)sum=0;
        }
        if(maxi<0) return maxi;
        return max(maxi, total-mini);
    }
};