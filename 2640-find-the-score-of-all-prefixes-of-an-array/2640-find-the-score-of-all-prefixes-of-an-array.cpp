class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> res;
        int maxi=nums[0];
        int prefSum=0;
        for(int i=0;i<nums.size();i++){
            // get max value 
            maxi=max(nums[i],maxi);
            int temp= nums[i]+maxi;
            prefSum+= temp;
            res.push_back(prefSum);
        }
        return res;

    }
};