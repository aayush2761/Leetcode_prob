class Solution {
public:
    // Follow-up:
    // What if the rectangle may be rotated? 
    // In other words, what if the sides are not necessarily parallel with the x-axis or y-axis?
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, set<int>>mp;
        for(auto & it: points){
            mp[it[0]].insert(it[1]);
        }
        int ans= INT_MAX;
        for(auto &it : mp){
            vector<int>s1;
            for(auto &e: it.second) s1.push_back(e);
            for(auto & i : mp){
                if(it.first==i.first) continue;
                 int length = abs(it.first - i.first);
                    int breadth=INT_MAX;
                 for(int x=0;x<s1.size();x++){
                    if(i.second.count(s1[x])){
                        for(int y=x+1;y<s1.size();y++){
                            if(i.second.count(s1[y])){
                                breadth = min(breadth, abs(s1[x] - s1[y]));
                            }
                        }
                    }
                    
                 }
                 if(breadth!= INT_MAX){
                    ans= min(ans, length*breadth);
                 }

            }
        }
        return ans==INT_MAX ? 0: ans;
    }
};