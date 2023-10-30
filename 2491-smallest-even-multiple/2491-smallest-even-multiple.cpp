class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n>=1 && n<=150){
            if(n%2==0) return n;
          
        }
        return n*2;
    }
};