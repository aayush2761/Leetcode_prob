#define pi pair<int,pair<int,int>>

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // num,ber-> row, index
        priority_queue<pi, vector<pi>, greater<pi>>pq;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini= min(nums[i][0],mini);
            maxi=max(nums[i][0],maxi);
            pq.push({nums[i][0],{i,0}});
        }
        // check each 
        int a = mini, b = maxi;
        while (!pq.empty()) {
            pi curr = pq.top();
            pq.pop();
            cout<<curr.first<<" "<<curr.second.first<<" "<<curr.second.second<<endl;
            if (curr.second.second + 1 < nums[curr.second.first].size()) {
                int r = curr.second.first, c = curr.second.second + 1;
                pq.push({nums[r][c], {r, c}});
                mini = pq.top().first;
                maxi = max(maxi, nums[r][c]);
                if (b-a > maxi-mini) {
                    a = mini;
                    b = maxi;
                }
            } else {
                break;
            }
        }
        return {a, b};
    }
};