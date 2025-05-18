class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res= max(res, prices[j]-prices[i]);
            }
        }
        return res;
    }
};
