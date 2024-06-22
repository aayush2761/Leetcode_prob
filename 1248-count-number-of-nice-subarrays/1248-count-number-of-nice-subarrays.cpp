// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<bool> isOdd(n, false);
//         for(int i = 0; i < n; i++) {
//             if(nums[i] % 2 != 0) isOdd[i] = true;
//         }
        
//         int i = 0, j = 0, count = 0, res = 0;
//         int prefix = 0;
        
//         while (i < n) {
//             if (isOdd[i]) count++;
            
//             // If we have exactly k odd numbers in the current window
//             if (count == k) {
//                 prefix = 0;
//                 // Count the number of subarrays that can be formed with the current window
//                 while (!isOdd[j]) {
//                     j++;
//                     prefix++;
//                 }
                
//                 // Move j to the next position for the next valid subarray
//                 res += (prefix + 1);
//                 count--;
//                 j++;
//             }
//             i++;
//         }
        
//         return res;
//     }
// };
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return findTotalSubArrays(nums, k) - findTotalSubArrays(nums, k - 1);
    }

    int findTotalSubArrays(vector<int>& nums, int k) {
        int i = 0, j = 0, subArrays = 0, countOdd = 0;

        while (j < nums.size()) {
            if (nums[j] % 2 != 0) { // Calculation part
                countOdd++;
            }

            while (countOdd > k) { // if condition fails
                if (nums[i] % 2 != 0) { // Remove the calculation part using i
                    countOdd--;
                }
                i++;
            }

            subArrays += j - i + 1; // Find all subarrays
            j++;
        }
        return subArrays;
    }
};