class Solution {
public:
    int maxFreeTime(int e, int k, vector<int>& start, vector<int>& end) {
        vector<int> diff;
        int n = start.size();
         diff.push_back(start[0] - 0);
        for (int i = 1; i < n; i++) {
            diff.push_back(start[i] - end[i - 1]);
        }
        diff.push_back(e - end[n - 1]);
        int res = 0, temp = 0;
        int i = 0, j = 0;

        for(auto it : diff){
            cout << it << " ";
        }

        while (i < diff.size()) {
            temp += diff[i];
            if (i - j <= k) {
                res = max(res, temp);
                i++;
            }
            if (i - j > k) {
                temp -= diff[j];
                j++;
            }
        }
        
        return res;
    }
};