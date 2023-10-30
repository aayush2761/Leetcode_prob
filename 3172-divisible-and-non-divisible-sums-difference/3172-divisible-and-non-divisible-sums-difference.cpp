/*class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1=0;
        int num2=0;
        for(int i=1;i<=n;i++){
            if(i%m!=0){
                num1=num1+i;
            }
        }
         for(int i=1;i<=n;i++){
            if(i%m==0){
                num2=num2+i;
            }
        }
        return num1-num2;
    }
};
*/
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum1 = 0,sum2 = 0;
        for(int i= 1; i<=n; i++) if(i%m!=0) sum1 += i;
        for(int i= 1; i<=n; i++) if(i%m==0) sum2 += i;
        return sum1-sum2;
    }
};