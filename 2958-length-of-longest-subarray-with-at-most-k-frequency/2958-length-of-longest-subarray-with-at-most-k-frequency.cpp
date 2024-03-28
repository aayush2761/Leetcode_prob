// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         unordered_map<int,int>mp;
//         int i=nums.size()-1,j=0;
//         int len=0;
//         while(i>=0){
//             mp[nums[i]]++;
//             int p=j;
//             while(p<=i){
//                if(mp[nums[p]]>k) {
//                 len=max(len,i-j+1);
//                 i--;
//                 mp.clear();
//                 break;
//                }
//                p++;
//             }
//             i--;
//         }
//        return len;
        
//     }
// };
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        //fo = first occurence
        unordered_map<int,queue<int>>fo;//store index of nums
        int n=size(nums);
        for(int l=0,r=0;r<n;r++){
            fo[nums[r]].push(r);

            //size of queue is frequency of element
            //if frequency is K+1 remove one
            if(fo[nums[r]].size()==k+1){
                //here l(left) is starting point of window
                //if first occurence is inside window update left (l)
                if(fo[nums[r]].front()>=l){
                    l=fo[nums[r]].front()+1;
                }
                fo[nums[r]].pop();
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};