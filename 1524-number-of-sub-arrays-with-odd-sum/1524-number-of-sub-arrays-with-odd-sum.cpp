class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0;
        int even = 1;  // Start with 1 to count the empty subarray
        int pref = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            pref = (pref + arr[i]) % mod;
            if (pref < 0) pref += mod;  // Ensure pref is non-negative
            if (pref % 2 == 1) {
                ans = (ans + even) % mod;
                odd++;
            } else {
                ans = (ans + odd) % mod;
                even++;
            }
        }
    return ans;
  }
};










// int mod= 1e9+7;
//     int numOfSubarrays(vector<int>& arr) {
        
//         int ans=0;
//         for(int i=0;i<arr.size();i++){
//             int temp=arr[i]%mod;
//             if(temp%2!=0) ans++;
//             for(int j=i+1;j<arr.size();j++){
//                 temp+= arr[j]%mod;
//                 if(temp%2!=0) ans++;
//             }
//         }
//         return ans;
//     }