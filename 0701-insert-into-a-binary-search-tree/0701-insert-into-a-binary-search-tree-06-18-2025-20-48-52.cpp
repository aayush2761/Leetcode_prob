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
    void insertedBST(TreeNode* root, int val){
        if(root==nullptr) return;
        if(root->left ==NULL && root->right==NULL){
            TreeNode *curr = new TreeNode(val);
            if(root->val>val){
                root->left= curr;

            }
            else root->right = curr;
            return;
        }
        if(val>root->val)insertedBST(root->right, val);
        if(val<root->val) insertedBST(root->left, val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            TreeNode *curr = new TreeNode(val);
            return curr;
        }
         insertedBST(root,val);
         return root;
    }
};