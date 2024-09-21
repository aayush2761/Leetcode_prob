class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int res = 0;
        for (int i = 0; i <= s.size() - k; i++) {
            int t = 0;
            for (int j = i; j < i + k; j++) {
                t = t * 10 + (s[j] - '0');
            }
            if (t == 0) continue;
            if (num % t == 0) res++;
        }
        return res;
    }
};