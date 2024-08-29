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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        //  vector<vector<int>> ans;
        if (root == nullptr) return 0; // Handle empty tree case
        priority_queue<long long , vector<long long>,greater<long long>>pq;


        queue<TreeNode*> q;
        q.push(root);
      
        while (!q.empty()) {
            int size = q.size();
            // vector<int> level;
            long long level=0;

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
            pq.push(level);
            if(pq.size()>k) pq.pop();

        }
        if(pq.size()<k) return -1;
        return pq.top();
    }
};