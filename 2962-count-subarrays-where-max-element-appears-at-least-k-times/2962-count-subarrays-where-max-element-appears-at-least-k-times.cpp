class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<long,long >freq;
        int n=nums.size();
        long long  element= *max_element(nums.begin(),nums.end());
        long long  i=0,j=0;
        long long ans=0;
        while(j<nums.size()){
            freq[nums[j]]++;
            while(freq[element]>=k){
                freq[nums[i]]--;
                ans+=(n-1)-j+1;
                i++;
            }
            j++;
     
        }
           return ans;
    }
};