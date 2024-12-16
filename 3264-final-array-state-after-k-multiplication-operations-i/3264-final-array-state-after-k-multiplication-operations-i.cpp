class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
             pq.push({nums[i],i});
        }
        while(k--){
            auto t= pq.top();
            // int 
            pq.pop();
            pq.push({t.first*m, t.second});
        }
        int n = nums.size();
        vector<int>res(n);
        while(!pq.empty()){
            auto i = pq.top();
            int ind=i.second;
            int val= i.first;
            res[ind]=val;
            pq.pop();
        }
        return res;
    }
};