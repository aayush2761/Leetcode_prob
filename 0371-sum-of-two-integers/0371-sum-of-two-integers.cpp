class Solution {
public:
    // int getSum(int a, int b) {
    //     // return a+b;
    // }
    int getSum(int a, int b) {
    return b==0? a:getSum(a^b, (a&b)<<1); //be careful about the terminating condition;
}
};