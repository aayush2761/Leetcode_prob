class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buy){
                buy= prices[i];
            }
            else res= max(res, prices[i]-buy);
        }
        return res;
    }
};