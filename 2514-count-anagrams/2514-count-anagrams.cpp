class Solution {
public:
    int countAnagrams(string str) {
        // Sliding window 
        // Find spaces 
        // Use factorial of len divided by repeating number 
        int res = 1;  // Initialize to 1 for multiplication
        int i = 0, j = 0;
        while (i < str.size()) {
            if (str[i] == ' ') {
                res *= helper(str.substr(j, i - j));
                j = i + 1;  // Move j to the next character after the space
            }
            i++;
        }
        if (j < str.size()) res *= helper(str.substr(j, i - j));  // Handle the last word

        return res;
    }

private:
    int helper(string s) {
        int len = s.size();
        unordered_map<char, int> mp;
        for (auto i : s) {
            mp[i]++;
        }
        unsigned long long temp = 1;
        for (auto i : mp) {
            temp *= factorialIterative(i.second);
        }
        unsigned long long num = factorialIterative(len);
        return num / temp;
    }

private:
    unsigned long long factorialIterative(int n) {
        unsigned long long result = 1;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
};
