class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int n=nums.size();
        vector<int> d(n*(n-1)/2);
        int index=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++)
                d[index++]=abs(nums[i]-nums[j]);
        }
        nth_element(d.begin(), d.begin()+(k-1), d.end());
        return d[k-1];
    }
};


// USING PRIORITY QUEUE

// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         priority_queue<int,vector<int>,greater<int>>pq;
//         int res=INT_MAX;
//         for(int i=0;i<nums.size()-1;i++){
//             for(int j=i+1;j<nums.size();j++){
//                 pq.push(abs(nums[i]-nums[j]));

//                 // if(pq.size()==k){
//                 //     res=pq.top();
//                 //     pq.pop();
//                 // }
//             }
//         }
//         for(int i=0;i<k;i++){
//             res=pq.top();
//             pq.pop();
//         }
//         return res;
//     }
// };