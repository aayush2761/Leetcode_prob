struct Node{
    TreeNode* result;
    int height;
};

class Solution {
public:
    Node depth(TreeNode* root){
        if(root==NULL) return {NULL,0};
        Node L=depth(root->left);
        Node R=depth(root->right);
        int new_height=max(L.height,R.height)+1;
        if(L.height>R.height) return {L.result,new_height};
        else if(L.height<R.height) return {R.result,new_height};
        else return {root,new_height};
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return depth(root).result;
    }
};