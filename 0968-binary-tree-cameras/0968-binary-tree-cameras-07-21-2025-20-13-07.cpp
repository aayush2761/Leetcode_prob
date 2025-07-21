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
    int postorder(TreeNode* root, int zero, int one, int two, int &camera){
        if(root==NULL) return zero; // already covered

        int left = postorder(root->left, zero, one,two,camera);
        int right = postorder(root->right, zero, one,two,camera);

        if(left==one || right==one ){
            camera++;
            return two;
            // i now have one camera
        }

        else if(left==two || right==two) return zero; // i dont required the camera 

        else return one;  // i want one camera 
    }
    int minCameraCover(TreeNode* root) {
        int camera=0;
        int zero =0; // covered 
        int one = 1 ; // i req camera 
        int two =2; // i have camera 
        int t= postorder(root, zero, one, two, camera);
        if(t==1) camera++;
        return camera;

    }
};