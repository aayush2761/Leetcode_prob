class Solution {
public:
    int maximumDifference(vector<int>& prices) {
        int mini=INT_MAX;
        int answer=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini) mini= prices[i];
            else answer= max(answer, prices[i]-mini);
        }
        return answer==0? -1: answer;
    }
};