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
//     int bubbleSort(vector<int>& nodes) {
//     int n = nodes.size();
//     int swaps = 0;
//     bool swapped;
//     for (int i = 0; i < n - 1; i++) {
//         swapped = false;
//         for (int j = 0; j < n - i - 1; j++) {
//             if (nodes[j] > nodes[j + 1]) {
//                 swap(nodes[j], nodes[j + 1]);
//                 swaps++;
//                 swapped = true;
//             }
//         }
//         if (!swapped) break;
//     }
//     return swaps;
// }
    int cycleSort(vector<int>& nums)
    {
      int n = nums.size();
        int len = n;
        map<int, int> map;
        for (int i = 0; i < len; i++)
            map[nums[i]] = i;
        sort(nums.begin(), nums.end());
        bool visited[len];
        for(int i = 0; i < len ; i++) visited[i] = false;
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
		 // already swapped and corrected or already present at correct pos
            if (visited[i] || map[nums[i]] == i)
                continue;
            int j = i, cycle_size = 0;
            while (!visited[j])
            {
                visited[j] = true;
				// move to next node
                j = map[nums[j]];
                cycle_size++;
            }
            if (cycle_size > 0)
            {
			// Update answer by adding current cycle.
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res=0;
        while(!q.empty()){
            int n =q.size();
            vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode* current = q.front();
                q.pop();
                level.push_back(current->val);

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            res+=cycleSort(level);


            }
        return res;
    }
};