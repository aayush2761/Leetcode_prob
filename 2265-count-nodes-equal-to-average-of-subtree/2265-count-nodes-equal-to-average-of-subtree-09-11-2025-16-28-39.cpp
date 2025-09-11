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
   pair<int,int> CountAverageSubtree( TreeNode* root, int &ans ){

        if(root==NULL) return {0,0};
        auto  left = CountAverageSubtree(root->left, ans);
        auto right = CountAverageSubtree(root->right, ans);

        int totalSum= root->val + left.first + right.first;
        int totalCount =1+ left.second + right.second;
        
        if((totalSum)/(totalCount)== root->val) ans++;

        return {totalSum, totalCount};
        }

    int averageOfSubtree(TreeNode* root) {
        if(root== NULL) return 0;
        int ans=0;
        CountAverageSubtree(root, ans);
        return ans;

    }
};