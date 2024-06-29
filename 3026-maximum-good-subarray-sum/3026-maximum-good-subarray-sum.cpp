class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // check for the nums[i]-+ k
        // the resulted answer will be sum_till_current_element - min_prefix_sum

        unordered_map<int , long long > mp;
        long long ans= LLONG_MIN;
        long long prefix_sum=0;
        for(int i=0;i<nums.size();i++){
            // search for nums[i]-k
            if(mp.find(nums[i]-k) !=mp.end()){
                ans= max(ans, prefix_sum + nums[i] - mp[nums[i] - k ]);
            }


            // search for nums[i]+k
             if(mp.find(nums[i]+k) !=mp.end()){
                ans= max(ans, prefix_sum + nums[i] - mp[nums[i] + k ]);
            } 
            // update with the min prefix sum 
            if(mp.find(nums[i])==mp.end()) mp[nums[i]] = prefix_sum;
            else  mp[nums[i]] = min(prefix_sum , mp[nums[i]]);

            // add element in prefix sum 
            prefix_sum+= nums[i];
        }
        if(ans==LLONG_MIN) ans=0;
        return ans;
    }
    // tc will be o(N) due to traversing and unordered map
    // sc will be o(N) due to unorederd map
};

// long long maximumSubarraySum(vector<int>& nums, int k) {
//         long long ans=INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             long long temp=nums[i];
//             for(int j=i+1;j<nums.size();j++){
//                 if(abs(nums[i]-nums[j])==k){
//                     temp+= nums[j];
//                     ans= max(ans,temp);
//                 }
//                 else temp+= nums[j];
//             }
//         }
//         if(ans==INT_MIN) return 0;
//         return ans ;
//     }