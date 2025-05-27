class Solution {
public:
    vector<int> countBits(int n) {
        int size= n+1;
        vector<int>result(size,0);
        for(int i=1;i<=n;i++){
            result[i]= __builtin_popcount(i);
        }
        return result;
    }
};