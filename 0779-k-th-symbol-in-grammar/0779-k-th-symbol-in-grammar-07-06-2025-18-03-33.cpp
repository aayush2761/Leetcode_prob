class Solution {
public:
    int kthGrammar(int n, int k) {
        int flip=0;
        long long total = (1<<(n-1));
        while(n>1){
            if(k>(total/2)){
                flip++;
                k-=(total/2);
            }
            total/=2;
            n--;
        }
        return 0+ (flip%2);
    }
};