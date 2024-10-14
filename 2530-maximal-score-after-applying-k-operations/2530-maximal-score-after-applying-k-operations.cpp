class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res=0;
        priority_queue<int>pq;
        // fill
        for(auto i : nums) pq.push(i);
        // extract 
        while(!pq.empty() && k>0){
            int t = pq.top();
            pq.pop();
            res+=t;
            cout<<t<<endl;
            int x= (int)ceil(t/3.0);
            // cout<<x<<endl;
            pq.push(x);
            k--;
        }
        return res;
    }
};