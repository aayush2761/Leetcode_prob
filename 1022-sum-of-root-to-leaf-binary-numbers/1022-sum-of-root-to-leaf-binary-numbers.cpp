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
    void sum(TreeNode* root, string &r,int &res){
        //preorder
        if(root==nullptr) {
            // res+=stoi(r, nullptr, 2);
            return;
        }
        // 
        char c= root->val +'0';
        r.push_back(c);
         if (root->left == nullptr && root->right == nullptr) {
            // Leaf node, compute the binary value
            res += stoi(r, nullptr, 2);
        }
        sum(root->left,r,res);
        sum(root->right,r,res);
        r.pop_back();

    }
    int sumRootToLeaf(TreeNode* root) {
        int res=0;
        string r="";
        sum(root,r,res);
        return res;
        
    }
};