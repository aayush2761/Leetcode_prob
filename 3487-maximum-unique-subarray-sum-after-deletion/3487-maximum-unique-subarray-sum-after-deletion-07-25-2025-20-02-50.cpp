class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        for(auto &it : nums){
            if(it>0) st.insert(it);
        }
        int ans=0;
        for(auto &it : st) ans+= it;
        if(ans==0) return *max_element(nums.begin(), nums.end());
        return ans;
    }
};