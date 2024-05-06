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
    void mapping(TreeNode* root,int distance,map<int,vector<int>>&mp){
        if (root == nullptr)
        return;
        
        mp[distance].push_back(root->val);
        if(root->left!=NULL) mapping(root->left,distance-1,mp);
        if(root->right!=NULL) mapping(root->right,distance+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>>mp;
        mapping(root,0,mp);
        vector<vector<int>>ans;
        for (auto& entry : mp) {
        sort(entry.second.begin(), entry.second.end());      
        ans.push_back(entry.second);
    }
    return ans;
    }
};