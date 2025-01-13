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
    int widthOfBinaryTree(TreeNode* root) {
        // indx-> (2*index+1, 2*index+2);
        queue<pair<TreeNode*,unsigned  long long>>q;
        q.push({root,0});
       unsigned  long long res=0;
        while(!q.empty()){
            long long size= q.size();
            unsigned long long left=-1,right=0;
            for(int i=0;i<size;i++){
                TreeNode* x= q.front().first;
                unsigned long long y= q.front().second;
                q.pop();
                if(x->left!=nullptr){
                    q.push({x->left, 2*y+1});
                }
                if(x->right!=nullptr){
                    q.push({x->right, 2*y+2});
                }
                if(left==-1)left=y;
                right=y;
            }
            res=max(res, right-left+1);

        }
        return (int)res;
    }
};