class Solution {
public:
    // Vector to store the sum of node values at each depth
    vector<int> depthSum;

    // First DFS to calculate the sum of node values at each depth
    void dfs1(TreeNode* root, int d) {
        if (!root) return;  // Base case: if the node is null, return

        // If the current depth is greater than or equal to the vector size,
        // add a new element with the current node's value
        if (d >= depthSum.size()) depthSum.push_back(root->val);
        // Otherwise, add the current node's value to the existing sum at this depth
        else depthSum[d] += root->val;

        // Recursively call dfs1 for left and right children, incrementing the depth
        dfs1(root->left, d + 1);
        dfs1(root->right, d + 1);
    }

    // Second DFS to replace node values
    void dfs2(TreeNode* root, int val, int d) {
        if (!root) return;  // Base case: if the node is null, return

        // Replace the current node's value with the passed 'val'
        root->val = val;

        // Calculate the sum of cousin nodes' values
        // If there's a next depth, get its sum, otherwise use 0
        int c = d + 1 < depthSum.size() ? depthSum[d + 1] : 0;
        // Subtract the values of the current node's children (if they exist)
        c -= (root->left != nullptr ? root->left->val : 0);
        c -= (root->right != nullptr ? root->right->val : 0);

        // Recursively call dfs2 for left and right children
        // Pass the calculated cousin sum 'c' and increment the depth
        if (root->left) dfs2(root->left, c, d + 1);
        if (root->right) dfs2(root->right, c, d + 1);
    }

    // Main function to replace values in the tree
    TreeNode* replaceValueInTree(TreeNode* root) {
        // First DFS to calculate depth sums
        dfs1(root, 0);
        // Second DFS to replace values, starting with 0 for the root
        dfs2(root, 0, 0);
        // Return the modified root
        return root;
    }
};