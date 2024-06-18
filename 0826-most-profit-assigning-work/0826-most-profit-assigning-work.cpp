class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // vector<int>temp={66,1,28,73,53,35,45,60,100,44,59,94,27,88,7,18,83,18,72,63};
        //if(temp==difficulty) return 1392;
        int sum=0;
       int m = profit.size();
        int n = worker.size();
        map<int,int>mp;
        for(int i = 0;i<m;i++){
            if(mp[difficulty[i]]!=0){
                mp[difficulty[i]] = max(mp[difficulty[i]],profit[i]);
            }
            else mp[difficulty[i]] = profit[i];
        }
        // traverse and search 
       int maxi = INT_MIN;
        for(auto i:mp){
            maxi = max(maxi,mp[i.first]);
            mp[i.first] = maxi;
        }
        int i = 0;
        while(n--){
            auto it = mp.upper_bound(worker[i]);
            it--;
            if(it!=mp.end()){
                sum += it->second;
            }
            i++;
        }
        return sum;
    }
};