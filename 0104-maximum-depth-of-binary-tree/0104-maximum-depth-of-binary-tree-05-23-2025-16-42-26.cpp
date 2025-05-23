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
    int count(TreeNode* root,int c, int & ans){
        if(root==nullptr) return 0;
        c++;
        ans=max(c,ans);
        count(root->left, c,ans);
        count(root->right, c,ans);
        return ans;
    }
    int maxDepth(TreeNode* root) {
        int ans=0;
        return count(root,0,ans);
    }
};