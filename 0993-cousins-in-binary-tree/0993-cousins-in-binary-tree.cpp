class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false; // Handle empty tree case
        
        vector<int> req;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        bool found = false;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            found = false;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Process the current node
                level.push_back(node->val);
                if (node->val == x || node->val == y) found = true;
                
                // Push children nodes to the queue
                if (node->left != nullptr && node->right != nullptr) {
                    // Check if x and y are siblings
                    if ((node->left->val == x && node->right->val == y) || 
                        (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            
            if (found) {
                req = level;
                break;
            }
            
            depth++;
        }
        
        if (depth <= 1) return false;
        
        // Check if x and y are present in the level
        bool px = false;
        bool py = false;
        for (auto i : req) {
            if (i == x) px = true;
            if (i == y) py = true;
        }
        return px && py;
    }
};
