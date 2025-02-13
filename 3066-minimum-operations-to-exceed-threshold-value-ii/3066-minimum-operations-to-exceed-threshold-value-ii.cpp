typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(auto it : nums) pq.push(it);
        int res=0;
        while(!pq.empty()){
            if(pq.top()>=k) break;
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ll temp = min(a,b)*2 +  max(a,b);
            pq.push(temp);
            res++;
        }
        return res;
    }
};