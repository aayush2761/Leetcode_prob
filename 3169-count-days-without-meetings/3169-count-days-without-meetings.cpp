class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int,int>diff;
        for(int i=0;i<meetings.size();i++){
            int left= meetings[i][0];
            int right= meetings[i][1];
            diff[left]++;
            diff[right+1]--;
        }
        int prev=0;
        int res=0;
        int curr=1;
        for(auto it=diff.begin();it!=diff.end();it++){
            it->second+=prev;
            if(prev==0) res+=it->first-curr;
            prev=it->second;
            curr=it->first;
        }
        res+=days-curr+1;
        return res;

    }
};
