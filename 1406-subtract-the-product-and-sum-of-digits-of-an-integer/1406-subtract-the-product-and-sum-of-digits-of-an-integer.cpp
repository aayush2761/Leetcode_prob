/*class Solution {
public:
    int subtractProductAndSum(int n) {
        int product=1;
        int sum=0;
        while(n!=0){
            int remainder=n%10;
            product=product*remainder;
            sum=sum+remainder;
            n=n/10;
        }
        return product-sum;
    }
};
*/
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum =0;
        int product=1;
        while(n>0)
        {
            int a = n % 10;
            n = n / 10;
            sum+=a;
            product = product*a;
        }
        return product-sum;
    }
};