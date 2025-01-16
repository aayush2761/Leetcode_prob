class Solution {
public:
    vector<int> fib = vector<int>(1000); 
    bool flag = false;
    int findMinFibonacciNumbers(int k) {
        if (!flag) {
            fib[0] = fib[1] = 1;
            for (int i = 2; i < 1000; i++) {
                fib[i] = fib[i - 1] + fib[i - 2];
                if (fib[i] > k) { 
                    fib.resize(i);
                    break;
                }
            }
            flag = true;
        }

        int res = 0;
        while (k > 0) {
            auto it = std::lower_bound(fib.begin(), fib.end(), k);
            if (*it > k) --it; 
            k -= *it; 
            res++;
        }
        return res;
    }
};
