class cmp{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const{
        if(a.first < b.first) return true;
        else if(a.first == b.first && a.second>b.second) return true;
        return false;
    }
};

class Solution {
public:
    // bool cmp
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto i : words) mp[i]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto i : mp){
            pq.push({i.second,i.first});
        }
        vector<string>res;
        while(!pq.empty() && k--){
            
                res.push_back(pq.top().second);
            pq.pop();
            
        }
        return res;
    }
};