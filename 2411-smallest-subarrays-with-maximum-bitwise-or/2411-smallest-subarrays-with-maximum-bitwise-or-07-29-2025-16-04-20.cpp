class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // smallest-subarrays
        int n = nums.size();
        vector<int>result(n);
        vector<int>bits(32,-1);
        for(int i =n-1;i>=0;i--){
            int farthest =i;
            for(int b=0;b<32;b++){
                if(nums[i]>>b & 1){
                    bits[b]=i; 
                }
                if(bits[b]!=-1) farthest= max(farthest, bits[b]);
            }
            result[i]= farthest-i+1;
        }
        return result;
    }
};