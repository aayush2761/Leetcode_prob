class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
        int n = s.size();

        // Calculate the size of the decoded string
        for (char c : s) {
            if (isdigit(c)) {
                int num = c - '0';
                size *= num;
            } else {
                size++;
            }
        }

        // Traverse the string backwards to find the k-th character
        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            k %= size;  // Reduce k to be within the current segment size

            if (k == 0 && isalpha(c)) {
                return string(1, c);
            }

            if (isdigit(c)) {
                int num = c - '0';
                size /= num;
            } else {
                size--;
            }
        }

        return "";  // Should not reach here normally
    }
};