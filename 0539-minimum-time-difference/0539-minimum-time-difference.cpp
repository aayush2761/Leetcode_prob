class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int minutes = INT_MAX;
        int n = timePoints.size();

        auto timeToMinutes = [](const string& time) -> int {
            int a1 = (time[0] - '0') * 10 + (time[1] - '0');
            int a2 = (time[3] - '0') * 10 + (time[4] - '0');
            return a1 * 60 + a2;
        };

        for (int i = 1; i < n; i++) {
            int time1 = timeToMinutes(timePoints[i - 1]);
            int time2 = timeToMinutes(timePoints[i]);
            minutes = min(minutes, time2 - time1);
        }

        int firstTime = timeToMinutes(timePoints[0]);
        int lastTime = timeToMinutes(timePoints[n - 1]);
        int wrapAround = (24 * 60) - lastTime + firstTime;
        minutes = min(minutes, wrapAround);

        return minutes;
    }
};
