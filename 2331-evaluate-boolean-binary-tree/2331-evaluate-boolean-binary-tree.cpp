// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

//  //postOrder traversal 
// class Solution {
// public:
//     bool evaluateTree(TreeNode* root) {
//         if(root==NULL) return root->val;

//         TreeNode* left =NULL;
//         if(root->left!=NULL) left= evaluateTree(root->left);
//         TreeNode* right=0;
//         if(root->right!=NULL) right= evaluateTree(root->right);

//         //logic 
//         if(root->val==2){
//             if(left->val==0 && right->val==0) return 0;
//             else if((left->val==0 && right->val==1) ||  (left->val==1 && right->val==0)) return 1;
//             else return 1;
//         }
//         else if(root->val==3){
//              if(left->val==0 && right->val==0) return 0;
//             else if((left->val==0 && right->val==1) ||  (left->val==1 && right->val==0)) return 0;
//             else return 1;
//         }
//     }
// };

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root == nullptr) return false; // Return false for null node

        // Base case: leaf node, return its value
        if (root->left == nullptr && root->right == nullptr)
            return root->val == 1;

        // Recursively evaluate left and right subtrees
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        // Apply logic based on the value of the current node
        if (root->val == 2) {
            return left || right;
        } else if (root->val == 3) {
            return left && right;
        }

        return false; // Default return
    }
};
