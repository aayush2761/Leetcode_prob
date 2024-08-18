// class Solution {
// public:
//     vector<int> resultsArray(vector<int>& nums, int k) {
//         dequeue<int>dq;
//         vector<int>res;
//         for(int i=0;i<nums.size();i++){
//             if(dq.size()>=k){
//                 if
//             }
//         }
//     }
// };



// class Solution {
// public:
//     vector<int> resultsArray(vector<int>& nums, int k) {
//         priority_queue<pair<int,int>>pq;

//         vector<int>res;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]-pq.top().first !=1){
//                 res.push_back(-1);
//                 pq.clear();
//             }
//             else{
//                 if(pq.size()==k){
//                     res.push_back(pq.top().first);
//                     // remove i-k+1 the index from the pq 
                    
//                 }
//             }
//         }
//         return res;
//     }
// };



class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
         deque<int>dq;
         int n= nums.size();
        vector<int>res(n-k+1,-1);
        // int maxi=INT_MIN;
        // first push k element 
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            // remove smaller elements 
            while(!dq.empty() && (nums[i]<nums[dq.back()] || nums[i]-nums[dq.back()]!=1)){
                dq.pop_back();
            }
            dq.push_back(i);
             if(!dq.empty() && dq.front()<=i-k){ 
                dq.pop_front();
            }
            
            if(i>=k-1){
                if(dq.size()>=k){
                    res[i-k+1] = nums[dq.back()]; 
                }  
            }
            
        }
           return res;
    }
};




// class Solution {
// public:
//     vector<int> resultsArray(vector<int>& nums, int k) {
//         if(k == 1) return nums;
//         vector<int> res;
//         int n = nums.size();
//         // check using fixed sliding window 
//         // i  to i+k
//         for(int i = 0; i <= n - k; i++) {
//             if(checkss(i, i + k - 1, nums)) {
//                 res.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
//             } else {
//                 res.push_back(-1);
//             }
//         }
        
//         return res;
//     }
//     // check function 
//     bool checkss(int s, int e , vector<int>& nums) {
//         for(int i = s; i < e; i++) {
//             if(nums[i] >= nums[i + 1] || nums[i + 1] - nums[i] != 1) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
// // solutoin second 
// // tc -> O(n) something 