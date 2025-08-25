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
    int check(TreeNode* root, bool &ans){
        if(root==NULL) return 0;
        if(!ans) return 0;
        int left = check(root->left, ans);
        int right= check(root->right, ans);
        if(abs(left-right)>1) ans= false;
        return 1+ max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return 1;
        bool ans= true;
        int temp= check(root, ans);
        return ans;
    }
};