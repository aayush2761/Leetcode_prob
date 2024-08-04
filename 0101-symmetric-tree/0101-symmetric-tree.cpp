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
    bool symmetricHelper(TreeNode* rootl, TreeNode* rootr){
        if(rootl == nullptr || rootr == nullptr) return rootl == rootr;

        if(rootl->val != rootr->val) return false;
        return  symmetricHelper(rootl->left, rootr->right) &&
                symmetricHelper(rootl->right, rootr->left);
    }

    bool isSymmetric(TreeNode* root) {
        // If the tree is empty or symmetric, return true
        return root == nullptr || symmetricHelper(root->left, root->right);
    }
};


// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (root == nullptr) return true; // Handle empty tree case
        
//         vector<vector<int>> ans; // Store level values
//         queue<TreeNode*> q; // Queue for level-order traversal
//         q.push(root);
      
//         while (!q.empty()) {
//             int size = q.size();
//             vector<int> level;

//             for (int i = 0; i < size; ++i) {
//                 TreeNode* node = q.front();
//                 q.pop();
                
//                 // Process the current node
//                 if (node == nullptr) {
//                     level.push_back(0); // Use 0 as a placeholder for null
//                 } else {
//                     level.push_back(node->val);
//                     // Push children nodes to the queue
//                     q.push(node->left);
//                     q.push(node->right);
//                 }
//             }           
//             ans.push_back(level); // Add the level to the result
//         }

//         // Check if each level is a palindrome
//         for (int i = 0; i < ans.size(); i++) {
//             int start = 0;
//             int end = ans[i].size() - 1;
//             while (start <= end) {
//                 if (ans[i][start] != ans[i][end]) return false;
//                 start++;
//                 end--;
//             }
//         }

//         return true;
//     }
// };
