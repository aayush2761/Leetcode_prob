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
    int solve(TreeNode* root, int &ans){
        if(root==NULL){
             return 0;
        }
        int left=0, right=0;
        // if(root->left) {
        //     if(root->val== root->left->val)left =1+ solve(root->left, ans);
        //     else left = solve(root->left, ans);
        // }
        // if(root->right) {
        //     if(root->val== root->right->val)right =1+ solve(root->right, ans);
        //     else right = solve(root->right, ans);
        // }
         if(root->left) {
            int temp = solve(root->left, ans);
            if(root->val == root->left->val) left = 1 + temp;
            else left = 0;
        }

        if(root->right) {
            int temp = solve(root->right, ans);
            if(root->val == root->right->val) right = 1 + temp;
            else right = 0;
        }
        ans= max(ans,left+ right);
        return  max(left, right);

    }
    int longestUnivaluePath(TreeNode* root) {
        int count=0, ans=0;
        solve(root, ans);
        return ans;
    }
};