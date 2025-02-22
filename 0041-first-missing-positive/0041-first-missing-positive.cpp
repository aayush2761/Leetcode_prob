class Solution {
public:
    unordered_map<int,int>mp;
    int firstMissingPositive(vector<int>& nums) {
        mp.clear();
        int low=INT_MIN;
        for(auto &it : nums){
            mp[it]++;
            low=max(low,it);
        }
        for(int i=1;i<=low;i++){
            if(mp.find(i)==mp.end()) return i;
        }
        return low>0 ? low+1 : 1;

    }
};