class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Pair capital and profit together
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Min heap to manage projects by their capital requirements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // Max heap to select the most profitable project available
        priority_queue<int> maxHeap;
        
        // Push all projects into the min heap
        for (auto project : projects) {
            minHeap.push(project);
        }
        
        // Perform up to k selections
        for (int i = 0; i < k; ++i) {
            // Move all projects that can be afforded into the max heap
            while (!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            
            // If there are no affordable projects, break
            if (maxHeap.empty()) break;
            
            // Select the most profitable project
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};


 // heap 
 // get w amount in heap 
   // take the top element from the heap 
   // proceed 
