class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        // code
        int n=changed.size();
        if(n&1)return {};
        vector<int>res;
        map<int,int>mp;
        for(auto i: changed)mp[i]++;
        for(int i=0;i<n;i++){
            if(mp[changed[i]]==0)continue;
            mp[changed[i]]--;
            // twice 
            if(mp[2*changed[i]]==0) return {};
            else mp[2*changed[i]]--;
            res.push_back(changed[i]);
        }
        return res;
    }
};