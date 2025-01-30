class Solution {
public:
    int res = 0;
    int helper(TreeNode* root, int prev) {
        if (!root) return 0;
        int left = helper(root->left, root->val);
        int right = helper(root->right, root->val);
        res = max(res, left + right); // Update result with longest path through this node
        if (root->val == prev) {
            return max(left, right) + 1; // Extend the path if values match
        }
        return 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        helper(root, root->val);
        return res;
    }
};
