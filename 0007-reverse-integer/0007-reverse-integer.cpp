
// class Solution {
// public:
//     int reverse(int x) {
//         bool isNegative = x < 0;
//         if (isNegative) {
//             x = -x;
//         }

//         int ans = 0;

//         while (x != 0) {
//             int t = x % 10;
//             x /= 10;

//             if (ans > (INT_MAX - t) / 10) {
//                 return 0;
//             }

//             ans = ans * 10 + t;
//         }

//         return isNegative ? -ans : ans;
//     }
// };
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};