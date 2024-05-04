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
    int maxPathSum(TreeNode* root) {
        int maximumSum=INT_MIN;
        findSum(root,maximumSum);
        return maximumSum;
    }
    int findSum(TreeNode* root , int &maximumSum){
        if(root==NULL) return 0;
        //get bthe left maximum and right mnaximum and add to the node 
        //maximise the sum for each and every node 
        int leftSum=max(0, findSum(root->left, maximumSum));
        int rightSum=max (0,findSum(root->right, maximumSum));

        maximumSum=max(maximumSum, leftSum+rightSum+ root->val);
         return root->val + max(leftSum,rightSum);
         return 1+ max(leftSum,rightSum);
    }
};