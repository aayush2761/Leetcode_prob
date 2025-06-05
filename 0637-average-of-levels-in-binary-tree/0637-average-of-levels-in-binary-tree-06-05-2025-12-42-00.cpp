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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>levelavgAnswer;
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double levelavg=0;
            int levelCount=0;
            for(int i=0;i<n;i++){
                auto curr = q.front();
                // level.push_back(curr->val);
                levelavg+= 1.0*curr->val;
                levelCount++;
                q.pop();
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            levelavgAnswer.push_back(levelavg/(levelCount*1.0));
        }
        return levelavgAnswer;
    }
};