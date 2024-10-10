class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                res = max(res, i - st.top());
                st.pop();
            }
        }

        return res;
    }
};


// ----------------------->      BRUTE FORCE       <-----------------------------//


// int maxWidthRamp(vector<int>& nums) {
//         int res=0;
//         for(int i=0;i<nums.size();i++){
//             int t= nums[i];
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[j]>=t) res= max(res,j-i);
//             }
//         }
//         return res;
//     }