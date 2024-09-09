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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m,vector<int>(n,-1));
         vector<vector<bool> > seen(m, vector<bool>(n, false));
    
    if (m == 0)
        return res;

    // Change in row index for each direction
    int dr[] = { 0, 1, 0, -1 };

    // Change in column index for each direction
    int dc[] = { 1, 0, -1, 0 };

    int r = 0, c = 0;

    int di = 0;

    ListNode*temp=head;


    for (int i = 0; i < m * n; ++i) {

        // Add current element to result vector
        int t=-1;
        if(temp!=NULL)  t= temp->val;
        else break;
        temp=temp->next;

        res[r][c]=(t);

        seen[r][c] = true;

        int newR = r + dr[di];
        int newC = c + dc[di];

        if (0 <= newR && newR < m && 0 <= newC && newC < n
            && !seen[newR][newC]) {

           
            r = newR;

           
            c = newC;
        }
        else {

           
            di = (di + 1) % 4;

            
            r += dr[di];

            
            c += dc[di];
        }
    }

 
    return res;
}
};