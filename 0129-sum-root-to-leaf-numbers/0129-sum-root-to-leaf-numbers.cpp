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
    int sumNode(TreeNode* root,int &answer, int temp){
        //preordertraversal
         if (root == nullptr) {
            return 0;  
        }
        // if(root==NULL){
        //     answer+= temp;       // left null but right not null so 
        //     temp/=10;            // so this cant be used check for both left+right
        //     return temp;
        // }
        temp= temp*10 + root->val;

         if (root->left == nullptr && root->right == nullptr) {
            answer += temp;  // Add the current path sum to the total answer
            return 0;  // Return 0 as we don't need to accumulate further for leaf nodes
        }

        if(root->left!=NULL) sumNode(root->left,answer,temp);
        if(root->right!=NULL) sumNode(root->right,answer,temp);
        return 0;
    }
    int sumNumbers(TreeNode* root) {
        int answer=0;
        sumNode(root,answer,0);
        return answer;
    }
};