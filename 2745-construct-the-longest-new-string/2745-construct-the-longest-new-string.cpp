class Solution {
public:
    int longestString(int x, int y, int z) {
        int res=0;
        // for z 
        res+=2*z;
        if(y==x){
            res+=4*x;
            return res;
        }
        res+=4*min(x,y)+2;
        return res;

    }
};