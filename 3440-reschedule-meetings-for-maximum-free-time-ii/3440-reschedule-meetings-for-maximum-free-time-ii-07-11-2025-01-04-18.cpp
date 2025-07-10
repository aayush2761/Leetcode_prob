class Solution {
public:
    int maxFreeTime(int e, vector<int>& start, vector<int>& end) {
        // Precompute the largest gap on the right for every position. ******
        // find gaps 
        int n = start.size();
        vector<int>gap;
        gap.push_back(start[0]);
        for(int i=0;i<n-1;i++){
            if(start[i+1]-end[i]>0)gap.push_back(start[i+1]-end[i]);
        }
        // last
        gap.push_back(e-end[n-1]);

        int sz = gap.size();
        vector<int> largestRight(sz, 0), largestLeft(sz, 0);
        for (int i = sz - 2; i >= 0; --i) {
            largestRight[i] = max(largestRight[i + 1], gap[i + 1]);
        }
        for (int i = 2; i < sz; ++i) {
            largestLeft[i] = max(largestLeft[i - 1], gap[i - 2]);
        }
        int res=0;
        for(int i=1;i<sz;i++){
            int size= end[i-1]- start[i-1];
            if(size<= max(largestLeft[i], largestRight[i])) res= max(res, gap[i-1]+ gap[i]+ size);
            res= max(res, gap[i-1]+gap[i]);
        }

        return res;

    }
};
















// class Solution {
// public:
//     bool check(map<int, int>& temp, map<int, int>& mp) {
//         for (auto& it : temp) {
//             if (mp.find(it.first) == mp.end() || mp[it.first] < it.second)
//                 return false;
//         }
//         return true;
//     }

//     int maxFreeTime(int e, vector<int>& start, vector<int>& end) {
//         vector<int> gap;
//         int left = 0;
//         int n = start.size();

//         // initial gap from 0 to start[0]
//         if (start[0] > 0) gap.push_back(start[0]);

//         for (int i = 0; i < n; i++) {
//             int g = start[i] - left;
//             if (g > 0) gap.push_back(g);
//             left = end[i];
//         }

//         // final gap from last end to eventTime
//         if (e > end[n - 1]) gap.push_back(e - end[n - 1]);

//         map<int, int> mp;
//         for (int g : gap) mp[g]++;
//         mp[0] = 2; // handle missing gaps safely

//         int answer = 0;

//         for (int i = 0; i < n; i++) {
//             int size = end[i] - start[i];
//             if (i + 1 < gap.size()) {
//                 map<int, int> temp;
//                 temp[gap[i]]++;
//                 temp[gap[i + 1]]++;
//                 temp[size]++;
//                 if (check(temp, mp)) {
//                     answer = max(answer, gap[i] + gap[i + 1] + size);
//                 }
//             }
//         }

//         return answer;
//     }
// };
