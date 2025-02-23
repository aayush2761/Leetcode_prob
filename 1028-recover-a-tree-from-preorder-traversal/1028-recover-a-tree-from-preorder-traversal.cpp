class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        stack<pair<int, TreeNode*>> st;
        int i = 0, n = s.size();
        
        while (i < n) {
            int depth = 0;
            while (i < n && s[i] == '-') {
                depth++;
                i++;
            }

            int value = 0;
            while (i < n && isdigit(s[i])) {
                value = value * 10 + (s[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(value);
            
            while (!st.empty() && st.top().first >= depth) {
                st.pop();
            }

            if (!st.empty()) {
                TreeNode* parent = st.top().second;
                if (!parent->left) parent->left = node;
                else parent->right = node;
            }

            st.push({depth, node});
        }
        
        while (st.size() > 1) st.pop(); 
        return st.top().second;
    }
};
