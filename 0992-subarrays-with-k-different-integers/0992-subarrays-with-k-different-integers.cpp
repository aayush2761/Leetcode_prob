// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//          long long ans=0;
//         unordered_map<long long,long long>mp;
//         for(long long l=0,r=0;r<nums.size();r++){
//             mp[nums[r]]++;
//             if(mp.size()==k) ans++;
//             if(r==nums.size()-1){
//                 r=l;
//                 l++;
                
//                 mp.clear();
//             }
//         }
//         return ans;

//     }
// };

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> count1, count2;
        int left1 = 0, left2 = 0;
        int distinct1 = 0, distinct2 = 0;

        for (int right = 0; right < n; ++right) {
            if (count1[nums[right]]++ == 0) distinct1++;
            if (count2[nums[right]]++ == 0) distinct2++;

            while (distinct1 > k) {
                if (--count1[nums[left1++]] == 0) distinct1--;
            }

            while (distinct2 > k - 1) {
                if (--count2[nums[left2++]] == 0) distinct2--;
            }

            ans += left2 - left1;
        }

        return ans;
    }
};
