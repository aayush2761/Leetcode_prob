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
    int solve(int x, int curr, TreeNode*root){
        if(root==NULL) return x;
        x= max(x,curr);
       if(root->left)  x = max(x, solve(x, curr+1, root->left));
        if(root->right) x = max(x, solve(x, curr+1, root->right));
        return x;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int x=1;
        int curr=1;
       return solve(x,curr,root);
        // return x;
    }
};