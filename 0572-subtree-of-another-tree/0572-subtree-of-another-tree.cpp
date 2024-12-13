class Solution {
public:
    void computeZArray(string& s, vector<int>& z) {
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
    }

    void getString(TreeNode* root, string& res) {
        if (root == nullptr) {
            res += "#,"; 
            return;
        }
        res += to_string(root->val) + ","; 
        getString(root->left, res);
        getString(root->right, res);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true; 
        if (root == nullptr) return false;  
        if(subRoot->left ==nullptr &&subRoot->right ==nullptr&& root->left ==nullptr&&root->left ==nullptr) return root==subRoot;



        string parent, child;
        getString(root, parent);
        getString(subRoot, child);

        string s = child + '$' + parent; 
        vector<int> z(s.size(), 0);
        computeZArray(s, z);
        for (int i = 0; i < z.size(); i++) {
            if (z[i] >= child.size()) return true;
        }
        return false;
    }
};
