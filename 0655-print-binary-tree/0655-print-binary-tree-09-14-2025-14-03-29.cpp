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
    int heightTree(TreeNode* root){
        if(root==NULL) return 0;
        int left = heightTree(root->left);
        int right = heightTree(root->right);
        return 1 + max(left, right);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        // Its left child goes to (row+1, col - 2^(height - row - 1)).
        // Its right child goes to (row+1, col + 2^(height - row - 1)).
        int height = heightTree(root) -1;
        if(height ==0) return {{to_string(root->val)}};

        int rows = height+1;
        int cols = pow(2,height+1)-1;

        vector<vector<string>>res(rows, vector<string>(cols,""));

        // bfs
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, (cols-1)/2}});

        while(!q.empty()){
            auto curr= q.front();
            q.pop();
            int r = curr.second.first;
            int c= curr.second.second;

            TreeNode* curr_node= curr.first;

            res[r][c]= to_string(curr_node->val);
            if(curr_node->left){
                q.push({curr_node->left, {r+1, c- pow(2, height-1-r)}});
            }
             if(curr_node->right){
                q.push({curr_node->right, {r+1, c+ pow(2, height-1-r)}});
            }
        }
        return res;



    }
};