class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
         if(k==0){
            unordered_map<int,int>mp;
            for(auto i : nums) mp[i]++;
            int res=0;
            for(auto i:mp)if((i.second)>1)res++;
            return res;
        }
        unordered_set<int>st(nums.begin(),nums.end());
       
        unordered_set<int>seen;
        for(auto i : st){
            if(st.count(i+k)){
                seen.insert(i);
            }
        }
        return seen.size();
    }
};