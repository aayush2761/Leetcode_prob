class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto it : words)mp[it]++;
        int res=0;
        int same =0;
        for(auto it : words){
            if(it[0]==it[1]){
                // cout<<"enter"<<endl;
                // cout<<mp[it]<<endl;
                same= max(same, mp[it]*2);
                continue;
            }
            string s = it;
            reverse(it.begin(),it.end());
            int itFreq= mp[it];
            int sFreq= mp[s];
            int total = min(itFreq,sFreq);
            res+= total*2*2;
            mp[it]-=total;
            mp[s]-=total;
            if(mp[it]<=0)mp.erase(it);
            if(mp[s]<=0)mp.erase(s);
        }
        return res+same;
    }
};