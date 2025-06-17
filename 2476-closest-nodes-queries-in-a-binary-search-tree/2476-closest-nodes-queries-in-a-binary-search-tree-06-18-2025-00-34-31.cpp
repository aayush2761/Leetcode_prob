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
    void helper(TreeNode* root,vector<int>& nodes ){
        // inordere traversal 
        if(root==NULL) return ;
         helper(root->left, nodes);
         nodes.push_back(root->val);
         helper(root->right, nodes);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>nodes;
        helper(root, nodes);
        vector<vector<int>>res;
        for(auto &it : queries){
            auto lb = lower_bound(nodes.begin(), nodes.end(), it);
            int index = lb- nodes.begin();
            if(index < nodes.size() && nodes[index]==it) res.push_back({it,it});
            else {
                int smaller = (index > 0) ? nodes[index - 1] : -1;
                int greater = (index < nodes.size()) ? nodes[index] : -1;
                res.push_back({smaller, greater});
            }
        }
        return res;
    }
};