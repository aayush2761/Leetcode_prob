class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::set<int> st(nums.begin(), nums.end());

        int maxi = 1;
        int currLen = 1;
        auto prev = st.begin();

        for (auto it = std::next(st.begin()); it != st.end(); ++it) {
            if (*it - *prev == 1) {
                ++currLen;
                maxi = std::max(maxi, currLen);
            } else {
                currLen = 1;
            }
            prev = it;
        }

        return maxi;
    }
};


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         if(n==0) return 0;
//         int indx=1,maxi=1;
//         for(int i=0;i<n-1;i++)
//         {
//             if(abs(nums[i+1]-nums[i])==1)
//             {
//                 indx++;
//                 maxi=max(indx,maxi);
//             }
//             else if(abs(nums[i+1]-nums[i])==0)  // MISSED BY ME 
//             {
//                 continue;
//             }
//             else
//             {   
//                 indx=1;
//             }
//         }
//         return maxi;
//     }

// };