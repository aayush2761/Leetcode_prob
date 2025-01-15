#define set_bits(x) __builtin_popcount(x)
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num1Bits = set_bits(num1);
        int num2Bits = set_bits(num2);

        int res = 0;
        for (int i = 31; i >= 0 && num2Bits > 0; i--) {
            if ((num1 & (1 << i)) != 0) {
                res |= (1 << i);
                num2Bits--;
            }
        }
        // Add remaining bits to make num2Bits match
        for (int i = 0; i <= 31 && num2Bits > 0; i++) {
            if ((res & (1 << i)) == 0) {
                res |= (1 << i);
                num2Bits--;
            }
        }
        return res;
    }
};
