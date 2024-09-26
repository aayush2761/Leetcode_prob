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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        // less than n 
        // level order
        queue<TreeNode*>q;
        q.push(root);
        int res=0;
        while(!q.empty()){
            int t=0;
            int s=q.size();
            for(int i=0;i<s;i++){
                t++;
                TreeNode* node = q.front();
                q.pop();

                // Push children nodes to the queue
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            res+=t;
        }
        return res;
    }
};