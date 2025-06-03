class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int answer=0;
        queue<int>q;
        int n = status.size();
        vector<int>visited(n,false);
        vector<bool> hasBox(n, false);
        for (auto box : initialBoxes) {
            q.push(box);
            hasBox[box] = true;
        }
        while (!q.empty()) {
            int element = q.front();
            q.pop();
            if (!status[element] || visited[element]) continue;
            visited[element] = true;
            answer += candies[element];
            for (auto key : keys[element]) {
                status[key] = 1;
                if (hasBox[key] && !visited[key]) {
                    q.push(key);  
                }
            }
            for (auto box : containedBoxes[element]) {
                if (!hasBox[box]) {
                    q.push(box);
                    hasBox[box] = true;
                }
            }
        }
        return answer;
    }
};