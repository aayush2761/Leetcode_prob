class Solution {
public:
    int minSteps(int n) {
        // return 0;
        int res=0;
        while (n % 2 == 0) {
        res+=2;
        n /= 2;
    }

    // n must be odd at this point, so we can skip even numbers
    for (int i = 3; i * i <= n; i += 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            res+=i;
            n /= i;
        }
    }

    // This condition is to check if n is a prime number
    // greater than 2
    if (n > 2)
        res+=n;

    return res;
    }
};