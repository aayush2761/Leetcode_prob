class Solution {
public:
    double myPow(double x, int n) {
        bool flag = false;
        if(n%2!=0)flag= true;
        double res= pow(x, n/2);
         res*= pow(x, n/2);
        if(flag && n>0) res*=x;
        if(flag && n<0) res/=x;
        // if(n<0) res= 1.00000/res;
        return res; 
    }
};