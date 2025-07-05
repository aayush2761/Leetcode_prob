/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        ListNode*temp= head;
        vector<vector<int>>res(n,vector<int>(m,-1));
         int left =0, right =m-1, bottom = n-1,top=0;
        while(left<=right && top<=bottom ){
            // top ke liye 
            for(int i= left;i<=right;i++){
                if(temp==nullptr) return res;
                res[top][i]=temp->val;
                // num++;
                temp= temp->next;
            }
            top++;
            // right column 
            for(int i=top;i<=bottom;i++){
                if(temp==nullptr) return res;
                res[i][right]= temp->val;
                // num++;
                temp= temp->next;
            }
            right--;
            // bootom 
            if(bottom>=top){
                 for(int i=right;i>=left;i--){
                    if(temp==nullptr) return res;
                    res[bottom][i]=temp->val;
                // num++;
                temp= temp->next;
                }
                 bottom--;
            }
            // left 
            if(left<=right){
                 for(int i=bottom;i>=top;i--){
                    if(temp==nullptr) return res;
                    res[i][left]=temp->val;
                    // num++;
                    temp= temp->next;
                }
                left++;
            }
        }
        return res;
    }
};