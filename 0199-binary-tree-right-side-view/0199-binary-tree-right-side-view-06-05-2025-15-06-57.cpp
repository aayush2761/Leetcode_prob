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
    void solve(TreeNode* root,vector<int>&ans, int height){
        if(root==NULL) return ;
        if(height== ans.size()){
            ans.push_back(root->val);
            
        }
        if(root->right)solve(root->right,ans,height+1);
        if(root->left) solve(root->left, ans,height+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>ans;
        solve(root,ans,0);
        return ans;

    }
};