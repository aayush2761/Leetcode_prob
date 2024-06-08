// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n= nums.size();
//         for(int i=0;i<n;i++){
//             int temp= nums[i];
//             for(int j=i+1;j<n;j++){
//                 if((nums[j]+ temp)%k==0 ) return true;
//                 else temp+= nums[j];
//             }
//         }
//         return false;
//     }
// };
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n= nums.size();
//          return util(nums,k,n,0,0);
//     }
//     bool util(vector<int>& nums, int k , int index , int size , int sum){
//         if(size>=2 && sum%k==0)
//             return true;
//         if(index==0)
//             return false;

//         // size >0 
//         if(size>0)
//             return util(nums, k,index-1,size+1, sum+nums[index-1]);
        
//         return util(nums, k,index-1,size+1, sum+nums[index-1]) || util(nums, k,index-1,size, sum);
//     }
// };


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    
        unordered_map<int, int> mp;
        int Sum = 0;
        mp[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            Sum += nums[i];
            if (k != 0) Sum %= k;
            
            // Check if the remainder has been seen before
            if (mp.find(Sum) != mp.end()) {
                if (i - mp[Sum] > 1)   // If subarray length is greater than 1, return true
                return true;
            } 
            else {            // Store the index of the first occurrence of the remainder
                mp[Sum] = i;
            }
        }
        // If no valid subarray is found, return false
        return false;
    }
};
