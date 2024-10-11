class Solution {
public:
    // Custom comparator as a struct
    // struct cmp {
    //     bool operator()(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
    //         if (a.first.first > b.first.first) return true;
    //         if (a.first.first == b.first.first) return a.first.second > b.first.second;
    //         return false;
    //     }
    // };

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int t_arrival = times[targetFriend][0];
    sort(begin(times), end(times));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> reserved;
    priority_queue<int, vector<int>, greater<int>> avail;    
    for (auto &t : times) {
        while (!reserved.empty() && reserved.top().first <= t[0]) {
            avail.push(reserved.top().second);
            reserved.pop();
        }
        if (t[0] == t_arrival)
            break;
        if (avail.empty())
            reserved.push({t[1], reserved.size()});
        else {
            reserved.push({t[1], avail.top()});
            avail.pop();
        }
    }
    return avail.empty() ? reserved.size() : avail.top();
}
};
