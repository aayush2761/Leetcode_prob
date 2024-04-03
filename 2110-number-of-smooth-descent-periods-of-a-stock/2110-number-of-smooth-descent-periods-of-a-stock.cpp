class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        deque<int>q;
        long long ans=0;
        int i=0;
        while(i<prices.size()){
            q.push_back(prices[i]);
            while((i+1<prices.size()) &&  (q.back()-prices[i+1]==1)){
                q.push_back(prices[i+1]);
                i++;
            }
            ans+=(q.size()*(q.size()+1))/2;
            i++;
            q.clear();
        }
        return ans;
    }
};