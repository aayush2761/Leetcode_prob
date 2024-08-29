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
    int maxLevelSum(TreeNode* root) {
        //  vector<vector<int>> ans;
        if (root == nullptr) return 0; // Handle empty tree case

        queue<TreeNode*> q;
        q.push(root);
       int index=1;
       int res=-1;
       int temp=INT_MIN;
        while (!q.empty()) {
            int size = q.size();
            // vector<int> level;
            int level=0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Process the current node
                // level.push_back(node->val);
                level+=node->val;

                // Push children nodes to the queue
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }           
            // ans.push_back(level); // Add the level to the result
            if(level>temp){
                temp=level;
                res=index;
            }
            index++;

        }

        // return ans;
        return res;
    }
};