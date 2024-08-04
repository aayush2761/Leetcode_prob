class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true; // Handle empty tree case
        
        vector<vector<int>> ans; // Store level values
        queue<TreeNode*> q; // Queue for level-order traversal
        q.push(root);
      
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Process the current node
                if (node == nullptr) {
                    level.push_back(0); // Use 0 as a placeholder for null
                } else {
                    level.push_back(node->val);
                    // Push children nodes to the queue
                    q.push(node->left);
                    q.push(node->right);
                }
            }           
            ans.push_back(level); // Add the level to the result
        }

        // Check if each level is a palindrome
        for (int i = 0; i < ans.size(); i++) {
            int start = 0;
            int end = ans[i].size() - 1;
            while (start <= end) {
                if (ans[i][start] != ans[i][end]) return false;
                start++;
                end--;
            }
        }

        return true;
    }
};
