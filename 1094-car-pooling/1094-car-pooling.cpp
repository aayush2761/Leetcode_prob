class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int c) {
        int prev=0;
        int curr=0;
        // pair<int,int
        map<int,int>mp;
        int total=0;
        for(auto i: trips){
            mp[i[1]]+=i[0];

            mp[i[2]]-=i[0];
        }
        // line sweep
        for(auto i : mp){
            curr+=i.second;
            // if(curr>prev){
            //     prev=curr;
            //     total+=i.second;
            //     if(total==c) return true;
            // }
            // else{
            //     prev=curr;
            //      total-=i.second;
            //     if(total==c) return true;
            if(curr>c) return false;
            
        }
        return true;
    }
};