class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
             if(pq.size()>k) pq.pop();
        }
        unordered_map<int,int>mp;
        vector<int>res;
        while(!pq.empty()){
           
           mp[pq.top()]++;
            pq.pop();
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!= mp.end()){
                 res.push_back(nums[i]);
                 mp[nums[i]]--;
            }
            if(mp[nums[i]]==0)mp.erase(nums[i]);
        }
        return res;
    }
};