class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if(n<0 && d<0 &&n % d == 0) return to_string(abs(n) /abs(d) );
        if(n % d == 0) return to_string(n / d);

        string res = "";
        if((n < 0) ^ (d < 0)) res += "-";

        long long num = llabs((long long)n);
        long long den = llabs((long long)d);

        res += to_string(num / den);
        res += ".";

        num %= den;
        unordered_map<long long, int> seen;

        while(num && !seen.count(num)) {
            seen[num] = res.size();
            num *= 10;
            res += to_string(num / den);
            num %= den;
        }

        if(num) {
            int idx = seen[num];
            res.insert(idx, "(");
            res += ")";
        }

        return res;
    }
};
