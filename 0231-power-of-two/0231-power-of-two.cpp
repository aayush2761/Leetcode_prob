class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long  t=1;
        int x=1;
        while(t<=n){
            if(t==n) return true;
            t=(long long )1<<x;
            x++;
        }
        return false;
    }
};