class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto & i : piles){
            pq.push(i);
        }
        while(k-- && !pq.empty()){
            int x = ceil(static_cast<double>(pq.top()) / 2);
            cout<<x<<endl;
            pq.pop();
            pq.push(x);
        }
        int res=0;
        while(!pq.empty()){
            res+=pq.top();
            pq.pop();
        }
        return res;
    }
};