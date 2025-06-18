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
 
    bool solve(TreeNode* root, int a, int b){
        if(root==NULL) return 1;
        if(root->val >= b || root->val<=a) return 0;
        return solve(root->left, a, root->val) && solve(root->right, root->val, b);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return 1;
           int a= INT_MIN, b = INT_MAX;
           return solve(root, a,b);
    }
};












//  if(root==NULL) return 1;
       
//         if(root->left && root->right){
//             if(root->val>root->left->val && root->val < root->right->val) return 1;
//             else return 0;
//         }
//         else if (root->left && ! root->right){
//             if(root->val>root->left->val ) return 1;
//             else return 0;
//         }
//         else if (!root->left &&  root->right){
//             if( root->val < root->right->val) return 1;
//             else return 0;
//         }
//         // else return 0;
//         return  isValidBST(root->left) &&  isValidBST(root->right);


// what im checking is the current node value hence it is not correct approach 
// eg   ----
//                  10
        //     /           \
        // 5                   12
        //                 /       \
        //             6               17
//                 ||||||   -> this 6 will pass but it not correct 