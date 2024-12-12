class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq(gifts.begin(),gifts.end());
           long long res=0;
        while(k--){
            int x= floor(sqrt((int)pq.top()));
            // res+=x;
            pq.pop();
            pq.push(x);
        }
     
        while(!pq.empty()){
            res+=pq.top();
            pq.pop();
        }
        return res;
    }
};