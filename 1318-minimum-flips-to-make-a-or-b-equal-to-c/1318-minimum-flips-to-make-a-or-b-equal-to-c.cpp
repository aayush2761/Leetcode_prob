class Solution {
public:
    int minFlips(int a, int b, int c) {
        // int x= a|b;
        // int y= x^c;
        return __builtin_popcount((a|b)^c)+popcount<uint>(a & b & ((a | b) ^ c));
    }
};