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
 // find the root
 // go to the extreme right and add the node right to it 
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) return helper(root);
        // create dummy node 
        TreeNode *dummy= root;
        while(root != NULL){
            // find the key in the left side 
            if(root->val >key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;

                }
                else root= root->left;
            }
             // find the key in the right side 
            else{
                 if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;

                }
                else root= root->right;
            }
        }
        return dummy;

    }
    // helper function to change the key right yo the extreme right of the key lefty value pair 
     TreeNode* helper(TreeNode* root){
        // edge case if no left is there 
        if(root->left==NULL) return root->right;
        else if (root->right==NULL) return root->left;
        // edge case for if there is no right there present 
        TreeNode* rightChild= root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;

     }
     // Helper function to get the extreme right of the key left side 
     TreeNode* findLastRight(TreeNode* root){
        if(root->right==NULL) return root;
        return findLastRight(root->right);
     }
};