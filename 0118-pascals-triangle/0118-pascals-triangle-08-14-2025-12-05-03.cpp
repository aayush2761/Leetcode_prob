class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        vector<int> prev;
        prev.push_back(1);
        int i=2;
        while(i<=numRows){
            res.push_back(prev);
            vector<int>curr(i);
            curr[0]=1,curr[i-1]=1;
            if(i==2){
                i++;
                prev=curr;
                continue;
            }
            for(int j=1;j<i-1;j++){
                curr[j]= prev[j]+ prev[j-1];
            }
            prev=curr;
            i++;
        }
        res.push_back(prev);
        return res;
    }
};