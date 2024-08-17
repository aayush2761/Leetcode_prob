class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>res;
        // int maxi=INT_MIN;
        // first push k element 
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            // remove smaller elements 
            while(!dq.empty() && nums[dq.back()]< nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }
           return res;
    }
};




// decreasing ordered to get the maximum 

// tc ->  O(N) + O(N)   iteratring elements + removing outof bound elements 
// sc->  O(K) for deque



// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int i = 0, j = 0;
//         vector<int> ans;
//         deque<int> temp;

//         while (i < nums.size()) {
          
//             while (!temp.empty() && temp.front() < i - k + 1) {
//                 temp.pop_front();
//             }

//             // Remove elements smaller than the current element
//             // while (!temp.empty() && nums[temp.back()] < nums[i]) {
//             //     temp.pop_back();
//             // }

//             temp.push_back(i);

//             if (i - j + 1 == k) {
//                 ans.push_back(nums[temp.front()]);
//                 temp.pop_front();
//                 j++;
//             }

//             i++;
//         }

//         return ans;
//     }
// };

