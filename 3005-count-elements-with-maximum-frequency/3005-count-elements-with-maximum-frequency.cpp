

class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        vector<int> v;
        for(auto i:mp){
            v.push_back(i.second);
        }
        sort(v.rbegin(),v.rend());
        int ans = v[0]; 
        for(int i = 1; i < v.size(); i++) {
            if(v[i] != v[i - 1]) break;
            ans += v[i];
        }
        return ans;
    }
};
