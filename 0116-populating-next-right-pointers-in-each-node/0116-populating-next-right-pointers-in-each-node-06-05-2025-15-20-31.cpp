/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
     void solve(Node* root,vector<Node*>&nodePointers, int height){
        if(root==NULL) return ;
        if (nodePointers[height] != nullptr) {
            nodePointers[height]->next = root;
        }
        nodePointers[height] = root;
        if(root->left) solve(root->left, nodePointers,height+1);
        if(root->right)solve(root->right,nodePointers,height+1);
    }
    Node* connect(Node* root) {
        vector<Node*>nodePointers(12,nullptr);
        solve(root,nodePointers,0);
        return root;
    }
};