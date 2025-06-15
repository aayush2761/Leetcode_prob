class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
            // if not found 
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]].first= i;
                mp[s[i]].second = i;
            }
            else {
                 mp[s[i]].second= i;
            }
        }
        // difference array 
        vector<int>diff(502,0);
        for(auto & it : mp){
            int left = it.second.first;
            int right = it.second.second;
            diff[left]++;
            diff[right]--;
        }
        vector<int>res;
        int j=0;
        for(int i=1;i<diff.size();i++){
            diff[i]+= diff[i-1];
        }
        bool flag = false;
        for(int i=0;i<diff.size();i++){
            if(diff[i]>0 && !flag){
                j=i;
                flag= true;
            }
            if(diff[i]==0 && flag){
                res.push_back(i-j+1);
                j=i+1;
                flag= false;
            }
        }
        return res;
    }
};