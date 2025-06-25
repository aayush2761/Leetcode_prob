
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        helper(0, 0, n, result, s);
        return result;
    }
private:
    void helper(int open, int close, int n, vector<string>& result, string s) {
        // Base case
        if (s.size() == 2 * n) {
            result.push_back(s);
            return;
        }

        // Add '(' if we have not yet reached the limit of `n`
        if (open < n) {
            helper(open + 1, close, n, result, s + '(');
        }

        // Add ')' if the number of ')' is less than the number of '('
        if (close < open) {
            helper(open, close + 1, n, result, s + ')');
        }
    }
};
