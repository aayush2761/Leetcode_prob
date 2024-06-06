// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         int n = hand.size();
//         if(n%groupSize!=0) return false;
//         //code
//         int arr[n];
//         for(int i=0;i<n;i++) arr[i]++;
//         // sliding window 
//         int i=0,j=0;
//         while(i<n-2){
//             if(arr[i]!=0){
//                 if(arr[i+1]==0 || arr[i+2]==0) return false;
//             }
//             while(arr[i]>0){
//                 arr[i]--;
//                 arr[i+1]--;
//                 arr[i+2]--;
//             }
//             i++;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) 
    {
        if(nums.size() % k) return false;

        map<int,int>mp;
        for(auto val:nums) mp[val]++;

        int n = nums.size();
        while(n--)
        {
            for(auto [a, b]:mp)
            {
                for(int i=a;i<a+k;i++)
                {
                    if(mp[i] == 0) return false;
                    mp[i]--;
                    if(mp[i]==0) mp.erase(i);
                }
                break;
            }
        }
        return true;
    }
};