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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>qu;
        qu.push(root);
        bool flag=false;
        while(!qu.empty()){
            int size=qu.size();
            vector<TreeNode*>v;
            
            for(int i=0;i<size;i++){
                TreeNode*node=qu.front();
                qu.pop();
                v.push_back(node);
                if(node->left!=NULL){
                    qu.push(node->left);
                }
                if(node->right!=NULL){
                    qu.push(node->right);
                }

            }
            int n=v.size();
            if(flag==true){
                for(int i=0;i<n/2;i++){
                    swap(v[i]->val,v[n-i-1]->val);
                }
            }

            flag=!flag;
        }
        return root;
    }
};