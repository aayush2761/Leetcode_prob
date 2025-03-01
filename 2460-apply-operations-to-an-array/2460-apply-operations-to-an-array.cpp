class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        int i=0;
        int zero=0;
        while(i<n-1){
            if(nums[i]==nums[i+1] && nums[i]!=0){
                res.push_back(nums[i]*2);
                i+=2;
                zero++;
            }
            else if(nums[i]==0) {
                zero++;
                i++;
            }
            else {
                res.push_back(nums[i]);
                i++;
            }
        }
        // if(nums[i]
        if(i==n-1)res.push_back(nums[i]);
        while(zero--)res.push_back(0);
        return res;
    }

};