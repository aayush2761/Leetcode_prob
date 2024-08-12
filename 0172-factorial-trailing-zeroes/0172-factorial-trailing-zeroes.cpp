// class Solution {
// public:
//     int trailingZeroes(int n) {
//         if(n<=4) return 0;
//         int fcount=0;
//         int tcount=0;
//         int t=n;
//         while(t>0){
//             if(t%5==0 && t>=5){
//                 t/=5;
//                 fcount++;
//             }
//             else if(t%2==0 && t>=2){
//                 t/=2;
//                 tcount++;
//             }
//         }
//         return min(tcount,fcount);

//     }
// };
class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5) return 0;
        int count = 0;
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        return count;
    }
};

// number of fives determine the number of trailing zeros 
