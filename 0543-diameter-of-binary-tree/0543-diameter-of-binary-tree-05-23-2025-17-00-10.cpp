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
    int diameterOfBinaryTree(TreeNode* root) {
        int maximumHeight=0;
        findHeight(root,maximumHeight);
        return maximumHeight;
    }
    int findHeight(TreeNode* root,int &maximum){
        if(root==NULL) return 0;
        int lh= findHeight(root->left , maximum);
        int rh= findHeight(root->right,maximum);
        maximum= max(maximum,lh+rh);
        return 1+ max(lh,rh);

    }
};