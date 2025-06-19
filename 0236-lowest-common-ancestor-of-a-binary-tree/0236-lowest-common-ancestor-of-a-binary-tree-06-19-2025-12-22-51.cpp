/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode* root, TreeNode* p){
        if(root==NULL) return 0;
        if(root==p) return 1;
        return find(root->left,p) || find(root->right,p);
    }
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q, bool pFind, bool qFind){
        if(root==NULL) return NULL;
        if(pFind && qFind) return root;
        
        if(root==p) pFind=true;
        if(root==q) qFind=true;
         helper(root->left,p,q,pFind,qFind);
         helper(root->right,p,q,pFind,qFind);
         return nullptr;
    }
    TreeNode* lcaHelper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode*leftN= lcaHelper(root->left,p,q);
        TreeNode* rightN= lcaHelper(root->right,p,q);

        if(leftN && rightN) return root;
        if(leftN) return leftN;
        return rightN;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return 0;
        bool findP = find(root,p);
        bool findQ = find(root,q);
        if(findP==NULL && findQ==NULL) return NULL;
        // now check LCA 
       return lcaHelper(root,p,q);
    }
};