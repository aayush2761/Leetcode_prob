class Solution {
public:
    int sumBase(int n, int k) {
        int bnum=0;
       
        while(n>0){
            bnum= bnum*10 + n%k;
            n/=k;

        }
        int add=0;
        while(bnum>0){
            add= add+ bnum%10;
            bnum/=10;
        }
        return add;
    }
};