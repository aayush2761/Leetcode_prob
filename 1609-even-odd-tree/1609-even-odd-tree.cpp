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
// class Solution {
// public:
//     bool isEvenOddTree(TreeNode* root) {
//         vector<vector<int>>Levels;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             int size= q.size();
//             vector<int>level;
//             for(int i=0;i<size;i++){
//                 TreeNode* node= q.front();
//                 q.pop();
//                 if(node->left!=NULL) q.push(node->left);
//                 if(node->right!=NULL) q.push(node->right);
//                 level.push_back(node->val);
//             }
//             Levels.push_back(level);
//         }

//         int i=0;
//         while(i<Levels.size()){
//             if(i%2==0){
//                 for(int j=1;j<Levels[i].size();j++){
//                     if(Levels[i][j]< Levels[i][j-1] || Levels[i][j-1]%2==0 ) return false;
//                     if(Levels[i][Levels[i].size()-1]%2==0) return false;
//                 }
//             }
//             else{
//                 for(int j=1;j<Levels[i].size();j++){
//                     if(Levels[i][j]> Levels[i][j-1] || Levels[i][j-1]%2!=0 ) return false;
//                     if(Levels[i][Levels[i].size()-1]%2!=0) return false;
//                 }
//             }
//             i++;
//         }
//         return true;
//     }
// };
