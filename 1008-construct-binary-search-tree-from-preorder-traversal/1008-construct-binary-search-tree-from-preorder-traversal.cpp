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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // convert pre order to inorder then convert inta trre it will be always A BST
        int ind=0;
        return helper(preorder , ind, INT_MAX);
    }
     TreeNode* helper(vector<int>& preorder , int &ind ,int bound){
        if(ind==preorder.size() || preorder[ind]>bound) return NULL;
        // create nod 
        TreeNode* root= new TreeNode(preorder[ind]);
        ind++;

        root->left= helper(preorder , ind , root->val);
        root->right= helper(preorder , ind , bound);
        return root;
     }
};