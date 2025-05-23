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
    int depth(TreeNode* root){
        if(root==NULL) return 0;
         int leftMax=  depth(root->left);
        int rightMax= depth(root->right);
        return 1+ max(leftMax, rightMax);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
       isBalanced(root->left);
       int a = depth(root->left);
       int b = depth(root->right);
       if(abs(a-b)>1)return 0;
       isBalanced(root->right);
       return true;

    }

};