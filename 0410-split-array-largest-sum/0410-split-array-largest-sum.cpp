class Solution {
public:
int helper(int maxBound, vector<int>& nums,int k) {
        int count = 1, temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (temp + nums[i] <= maxBound) {
                temp += nums[i];
            } else {
                count++;
                temp = nums[i];
            }
        }
        return count<=k; 
    }
    int splitArray(vector<int>& nums, int k) {
        // binary saerch 
        int result=0;
        int low= *max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid= low +(high-low) /2;
            if(helper(mid,nums,k)){
                result=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return result;
    }
};