/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans; // Handle empty tree case

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; // Flag to indicate the traversal direction

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Process the current node
                level.push_back(node->val);

                // Push children nodes to the queue
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            // Apply zigzag ordering based on the flag
            if (!flag) {
                reverse(level.begin(), level.end()); // Reverse the level vector
            }
            ans.push_back(level); // Add the level to the result

            // Toggle the flag for the next level
            flag = !flag;
        }

        return ans;
    }
};