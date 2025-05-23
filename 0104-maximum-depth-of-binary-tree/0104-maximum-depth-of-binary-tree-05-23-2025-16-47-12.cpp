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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        vector<vector<int>>res;
        queue<TreeNode*>qt;
        qt.push(root);
        while(!qt.empty()){
            vector<int>level;
            int size= qt.size();
            for(int i=0;i<size;i++){
                auto it = qt.front();
                qt.pop();
                level.push_back(it->val);
                if(it->left!=NULL)qt.push(it->left);
                if(it->right!=NULL)qt.push(it->right);
            }
            res.push_back(level);
        }
        return res.size();
    }
};