
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mp;
        
        for (auto i : arr) {
            mp[i]++;
        }

        vector<pair<int, int>> v;
        for (auto i : mp) {
            v.push_back(make_pair(i.second, i.first));
        }

      sort(v.begin(), v.end());

       int ans=v.size(),i=0;
        while(k>0){
            while(v[i].first>0 && k>0){
                v[i].first--;
                k--;
            }
            if(v[i].first==0){
                i++;
                ans--;
            }
        }
        return ans;
    }
};
