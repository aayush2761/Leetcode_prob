class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>v(n+2,0);
        for(auto i : bookings){
            int l=i[0];
            int r=i[1];
            int val=i[2];
            v[l]+=val;
            v[r+1]-=val;
        }
        // add to kar bhai
        for(int i=1;i<=n;i++){
            v[i]+=v[i-1];
        }
        vector<int>res;
        for(int i=1;i<=n;i++) res.push_back(v[i]);
        return res;
    }
};