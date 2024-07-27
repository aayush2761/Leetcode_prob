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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>avg;
        // vector<vector<int>>levels;
        queue<TreeNode*>qt;
        qt.push(root);
        while(!qt.empty()){
            int size= qt.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                 TreeNode* node = qt.front();
                 qt.pop();
                 if(node->left!=NULL)qt.push(node->left);
                 if(node->right!=NULL)qt.push(node->right);
                 level.push_back(node->val);
            }
            // average value
            double t=0;
            for(auto i : level){
                t+=i;
            }
            t*=1.0;
            avg.push_back(t/level.size());
            level.clear();
        
        }
        return avg;
    }
};