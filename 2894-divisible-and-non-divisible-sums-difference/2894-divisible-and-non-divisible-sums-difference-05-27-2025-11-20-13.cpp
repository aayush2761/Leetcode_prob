class Solution {
public:
    int differenceOfSums(int n, int m) {
        int req= (n*(n+1))/2;
        int remo=0;
        for(int i=1;i<=n;i++){
            if(i%m==0)remo+=i;
        }
        return req-(2*remo);
    }
};