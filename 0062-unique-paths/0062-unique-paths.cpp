class Solution {
public:
    int uniquePaths(int m, int n) {
        long long  res=1;
        int r= m-1;
        int d= n-1;
        int total = r+d;
        for(int i=1;i<=(min(r,d));i++){
            res=(res*(total-i+1))/i ;
        }
        return res;
    }
};