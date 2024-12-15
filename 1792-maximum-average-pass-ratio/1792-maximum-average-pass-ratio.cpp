#define d double
class Solution {
public:
    d getDelta(int pass, int total) {
    return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // priority_queue<pair<d, pair<int, int>>, vector<pair<d, pair<int, int>>>, greater<pair<d, pair<int, int>>>> pq;
         priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& i : classes) {
           int pass = i[0];
            int total = i[1];
           pq.push({getDelta(pass,total),{pass,total}}) ;
        }
        while (extraStudents--) {
            int pass = pq.top().second.first ; 
         int total  =  pq.top().second.second ; 
         pass++ ;
         total++ ; 
         pq.pop();
         pq.push({getDelta(pass,total),{pass,total}}) ; 
        }
        d res = 0.0;
        while (!pq.empty()) {
            auto i = pq.top();
            pq.pop();
            res += (d)i.second.first/i.second.second;
        }

        return res / classes.size();
    }
};
