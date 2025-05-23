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
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
	// queue
	queue<TreeNode*>queueNode;
	queueNode.push(root);
vector<vector<int>>levelOrderVector;
	while(!queueNode.empty()){
		int queueSize= queueNode.size();
		vector<int>level;
		for(int i=0;i<queueSize;i++){
			TreeNode* currentNode= queueNode.front();
			queueNode.pop();
			level.push_back(currentNode->val);
			if(currentNode->left!=NULL) queueNode.push(currentNode->left);
			if(currentNode->right!=NULL) queueNode.push(currentNode->right);
}
levelOrderVector.push_back(level);

}
// result computation part 
int result=1;
for(int i=1;i<levelOrderVector.size();i++){
	for(int j=0;j<levelOrderVector[i].size();j++){
		if(levelOrderVector[i][j]>=root->val)result++;
}
}
return result;

    }
};