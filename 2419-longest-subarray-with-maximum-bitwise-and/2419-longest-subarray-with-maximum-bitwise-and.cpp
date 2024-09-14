class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // and of two number cannot be greater than maximum value ever 
        // it can be min of both the two
        int res=INT_MIN;
        for(auto i : nums) res=max(res,i);
        // return res;
        // find the continous subaaray of res
        int ans=1,currentLength=0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == res) {
                currentLength++;  
            } else {
                ans = max(ans, currentLength); 
                currentLength = 0;  
            }
        }
        return ans;
    }
};



//    ------------------ BRUTE FORCE -------------------------------
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int res = *max_element(nums.begin(), nums.end()); // Maximum element in the array
//         int ans = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             int temp = nums[i];
//             int len = 1;

//             if (temp == res) len = 1; // Single element can be a subarray

//             for (int j = i + 1; j < nums.size(); j++) {
//                 temp &= nums[j];
//                 if (temp == res) {
//                     len = j - i + 1; 
//                 } else break;
//             }

//             ans = max(ans, len); 
//         }

//         return ans;
//     }
// };
