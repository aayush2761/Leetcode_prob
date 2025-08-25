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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
         if(root==NULL) return ans;
         queue<TreeNode*>q;
         q.push(root);
         bool left=false;
         while(!q.empty()){
            int s = q.size();
            vector<int>level;
            for(int i=0;i<s;i++){
                level.push_back(q.front()->val);
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();
            }
           if(!left) ans.push_back(level);
           else {
            reverse(level.begin(), level.end());
            ans.push_back(level);
           }
           left=!left;
         }
         return ans;
    }
};