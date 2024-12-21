class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int maxX = INT_MIN;
        int maxY = INT_MIN;
        for (int i = 0; i < rectangles.size(); i++) {
            maxX = max(maxX, max(rectangles[i][0], rectangles[i][2]));
            maxY = max(maxY, max(rectangles[i][1], rectangles[i][3]));
        }

        // X-axis processing
        vector<pair<int, int>> ppX;
        for (auto& rect : rectangles) {
            ppX.push_back({rect[0], rect[2]});
        }
        sort(ppX.begin(), ppX.end());
        int ansX = 0;
        int prevX = ppX[0].second;
        for (int i = 1; i < ppX.size(); i++) {
            int currStart = ppX[i].first;
            if (prevX <= currStart) {
                ansX++;
            }
            prevX = max(prevX, ppX[i].second);
        }

        if (ansX >= 2) return true;

        // Y-axis processing
        vector<pair<int, int>> ppY;
        for (auto& rect : rectangles) {
            ppY.push_back({rect[1], rect[3]});
        }
        sort(ppY.begin(), ppY.end());
        int ansY = 0;
        int prevY = ppY[0].second;
        for (int i = 1; i < ppY.size(); i++) {
            int currStart = ppY[i].first;
            if (prevY <= currStart) {
                ansY++;
            }
            prevY = max(prevY, ppY[i].second);
        }

        if (ansY >= 2) return true;
        return false;
    }
};
