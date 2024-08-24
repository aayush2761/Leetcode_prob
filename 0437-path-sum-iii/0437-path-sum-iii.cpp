// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
// int temp=0,res=0;
//  void solve(TreeNode* root, int t, int& res, int& temp) {
//         if (root == NULL) return;  // Base case: if root is NULL, return
        
//         temp+=root->val;  // Include current node's value
        
//         if ( t == root->val) {  // If it's a leaf node and the target sum is achieved, add the path to results
//             res++;
//         }
//             // Recursively call left and right with reduced sum
//             solve(root->left, t - root->val, res, temp);
//             solve(root->right, t - root->val, res, temp);
        

//         temp-=root->val;  // Backtrack to explore other paths
        
//         // left 
//         // solve(root->left, t, res, temp);  // These calls should be removed from the main flow
        
//         // root
//         // if (t >= root->val) { 
//         //     temp.push_back(root->val); 
//         //     solve(root, t - root->val, res, temp);  
//         //     temp.pop_back();  
//         // }

//         // right 
//         // solve(root->right, t, res, temp);  // These calls should be removed from the main flow
//     }

//     int pathSum(TreeNode* root, int t) {
//         if(root==NULL) return 0;
//          solve(root, t, res, temp);
//          pathSum(root->left,t);
//          pathSum(root->right,t);


//         return res;
//     }
// };


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
    int res = 0;  // To store the total number of paths

    // Function to find paths that sum to t from a given node
    void solve(TreeNode* root, long long  t) {
        if (root == NULL) return;

        // Check if the current node completes a path sum
        if (t == root->val) {
            res++;
        }

        // Continue searching in left and right children
        solve(root->left, t - root->val);
        solve(root->right, t - root->val);
    }

    // Main function to count all paths that sum to t
    int pathSum(TreeNode* root, int t) {
        if (root == NULL) return 0;

        // Check paths that start from the current node
        solve(root, (long long)t);

        // Recursively check paths from the left and right child nodes
        pathSum(root->left, t);
        pathSum(root->right, t);

        return res;
    }
};
