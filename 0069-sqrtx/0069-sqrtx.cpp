class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        
        if((x>=0 && x<=INT_MAX)){
            float d =0;
            d= floor(pow(x,0.5))*1;
            ans=d;
        }
        return ans;
    }
};