class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int n = digits.size();
        int carry = 1; // Start with carry as 1, since we are adding one to the number

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            if (sum == 10) {
                res.push_back(0);
                carry = 1; // Carry over to the next significant digit
            } else {
                res.push_back(sum);
                carry = 0; // No carry needed anymore
            }
        }

        if (carry > 0) res.push_back(carry); // Add carry if any left after the loop

        reverse(res.begin(), res.end()); // Reverse to get the correct order
        return res;
    }
};
