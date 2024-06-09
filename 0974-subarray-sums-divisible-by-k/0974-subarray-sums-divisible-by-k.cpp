 class Solution {
// public:           
//     int subarraysDivByK(vector<int>& nums, int k) {
//         unordered_map<int,int>mp;
//         mp[0]++;
//         int pref=0;
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             pref+= nums[i];
//             // 
//         //     int rem= pref%k;
//         //     auto it= rem;
//         //     mp.find(it);
//         //     if(!mp.end()){
//         //         count+= it->second;
//         //         it->second++;
//         //     }
//         //     else mp[rem]++;
//         // }
//         int rem = pref % k;
//            auto it = mp.find(rem); // Corrected this line
//            if (it != mp.end()) {   // Corrected this line           
//                count += it->second;
//                it->second++;
//            } else {
//                mp[rem]++;
//            }
//         }
//         return count;
//     }
// };class Solution {
public:           
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int pref = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            int rem = pref % k;
            // most important line 
            if(rem<0) rem+=k;
            auto it = mp.find(rem);
            if (it != mp.end()) {
                count += it->second;
                it->second++;
            } else {
                mp[rem]++;
            }
        }
        return count;
    }
};
