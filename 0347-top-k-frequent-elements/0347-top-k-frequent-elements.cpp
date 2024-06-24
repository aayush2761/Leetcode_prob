class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        // max heap
        priority_queue<pair<int,int>>maxH;
        for(auto& i :  mp){
            maxH.push({-i.second, i.first});
            // 
            if(maxH.size()>k) maxH.pop();
        }
        vector<int>res;
        while(!maxH.empty()){
            res.push_back(maxH.top().second);
            maxH.pop();
        }
        return res;
    }
};