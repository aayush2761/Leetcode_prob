class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it : nums){
            if(st.find(it)!=st.end())return it;
            st.insert(it);
        }
        return -1;

    }
};