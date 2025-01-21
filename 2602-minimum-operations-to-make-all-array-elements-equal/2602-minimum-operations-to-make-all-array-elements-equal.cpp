class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int m = queries.size();
        vector<long long> res(m);
        for (int i = 0; i < m; i++) {
            int query = queries[i];
            auto pos = lower_bound(nums.begin(), nums.end(), query) - nums.begin();
            long long left_cost = (long long)query * pos - prefix[pos];
            long long right_cost = (prefix[n] - prefix[pos]) - (long long)query * (n - pos);
            
            res[i] = left_cost + right_cost;
        }
        return res;
    }
};



// tc -> queries.lenght * nums(len) * 30

// class Solution {
// public:
//     int check(vector<int>& nums,int k, int mid ){
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             count+=abs(k-nums[i]);
//             if(count>mid)return 0;
//         }
//         return 1;
//     }
//     int compute(vector<int>& nums,int k){
//         int low=0,high=1e9;
//         int res=0;
//         while(low<=high){
//             int mid= low + (high-low) /2;
//             if(check(nums,k,mid)){
//                 res=mid;
//                 high=mid-1;

//             }
//             else low=mid+1;
//         }
//         return res;
//     }
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//         // km operations mein pura krna ---> 00000001111111111..
//         // bs 
//         int m = queries.size();
//         vector<long long>res(m);
//         for(int i=0;i<m;i++){
//             res[i]= (long long)compute(nums,queries[i]);
//         }
//         return res;
//     }
// };