class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // min heap
        priority_queue< pair<int,pair<int,int>> > pq;
        
        // Traverse through all points
        for(int i = 0; i < points.size(); i++) {
            int x = ( points[i][0]*points[i][0] + points[i][1]*points[i][1] );
            // Insert into priority queue
            pq.push({x, { points[i][0], points[i][1] }});
            
            // Maintain heap size <= k
            if(pq.size() > k) pq.pop();
        }
        
        // Prepare result
        vector<vector<int>> res;
        while(!pq.empty()) {
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            res.push_back({a, b});
            pq.pop();
        }
        
        return res;
    }
};
