class Solution {
public:

    int nthUglyNumber(int n) {
        
        unordered_map<long long, int> map;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        pq.push(1);
        int count= 0;
        long long popped;
        
        while(count<n){
            popped= pq.top();
            pq.pop();
            if(map[popped]== 0){
                pq.push(popped*2);
                pq.push(popped*3);
                pq.push(popped*5);
                count++;
                map[popped]= 1;
            }
        }
        return int(popped);
    }
};