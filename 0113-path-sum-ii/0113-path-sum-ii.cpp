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
    void solve(TreeNode* root, int t, vector<vector<int>>& res, vector<int>& temp) {
        if (root == NULL) return;  // Base case: if root is NULL, return
        
        temp.push_back(root->val);  // Include current node's value
        
        if (root->left == NULL && root->right == NULL && t == root->val) {  // If it's a leaf node and the target sum is achieved, add the path to results
            res.push_back(temp);
        } else {
            // Recursively call left and right with reduced sum
            solve(root->left, t - root->val, res, temp);
            solve(root->right, t - root->val, res, temp);
        }

        temp.pop_back();  // Backtrack to explore other paths
        
        // left 
        // solve(root->left, t, res, temp);  // These calls should be removed from the main flow
        
        // root
        // if (t >= root->val) { 
        //     temp.push_back(root->val); 
        //     solve(root, t - root->val, res, temp);  
        //     temp.pop_back();  
        // }

        // right 
        // solve(root->right, t, res, temp);  // These calls should be removed from the main flow
    }

    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(root, t, res, temp);
        return res;
    }
};
