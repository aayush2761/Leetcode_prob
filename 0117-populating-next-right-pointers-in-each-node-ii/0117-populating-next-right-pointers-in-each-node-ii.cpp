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
    Node* connect(Node* root) {
         if (root == nullptr) return nullptr; // Handle empty tree case

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr; // Track the previous node in the same level

            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();

                if (prev != nullptr) {
                    prev->next = node;
                }
                prev = node;

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            // The last node in each level should point to nullptr
            prev->next = nullptr;
        }

        return root;
    }
};