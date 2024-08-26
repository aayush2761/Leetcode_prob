/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans; // Handle empty tree case

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                // Process the current node
                level.push_back(node->val);

                // Push children nodes to the queue
                // if (node->left != nullptr) q.push(node->left);
                // if (node->right != nullptr) q.push(node->right);
                 for(auto x:node->children){
                     q.push(x);
                 }
            }
            ans.push_back(level); 
        }

        return ans;
    }
};