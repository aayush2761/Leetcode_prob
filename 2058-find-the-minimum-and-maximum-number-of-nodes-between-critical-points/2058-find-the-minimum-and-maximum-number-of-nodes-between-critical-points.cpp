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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int a=-1,b=-1;
        vector<int>points;
        int count=1;
        ListNode* temp=head;
        int prev= temp->val;
        while(temp->next!=NULL){
            count+=1;
            // maxima 
            if(temp->val > prev && temp->val> temp->next->val) points.push_back(count-1);
            // minima
            if(temp->val < prev && temp->val< temp->next->val) points.push_back(count-1);

            // changing prev 
            prev=temp->val;
            temp=temp->next;
        }
        // diffrence btw points

        int n =points.size();
       
        if(count<=3 || n==0 || n==1) return {a,b};
       int res1=INT_MAX;
       int res2=INT_MIN;
       for(int i=1;i<n;i++){
        res1=min(points[i]-points[i-1], res1);
       }
       res2= *max_element(points.begin(),points.end()) - *min_element(points.begin(),points.end());
        return {res1,res2};
    }
};