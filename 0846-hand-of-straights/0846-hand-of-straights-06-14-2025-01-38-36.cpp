class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int g) {
        map<int,int>mp;
        for(auto &it : nums)mp[it]++;
        int n= nums.size();
        if(n%g!=0) return 0;
        // if(g==n) return 1;
        vector<int>temp;
        while(mp.size()>0){
            // imp condition
            if(mp.size()<g) return 0;
            int p=0;
            for(auto it = mp.begin(); it != mp.end(); ) {
                temp.push_back(it->first);
                it->second--;
                if(it->second == 0) {
                    it = mp.erase(it);
                } else {
                    ++it;
                }
                p++;
                if(p == g) break;
            }
            // for(int i=0;i<temp.size();i++){
            //     cout<<temp[i]<<" ";

            // }
            // cout<<endl;
            for(int i=1;i<temp.size();i++){
                if(temp[i]-temp[i-1]!=1) return 0;

            }
            temp.clear();
        }
        return 1;
    }
};
class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int g) {
        map<int,int>mp;
        for(auto &it : nums)mp[it]++;
        int n= nums.size();
        if(n%g!=0) return 0;
        // if(g==n) return 1;
        vector<int>temp;
        while(mp.size()>0){
            // imp condition
            if(mp.size()<g) return 0;
            int p=0;
            for(auto it = mp.begin(); it != mp.end(); ) {
                temp.push_back(it->first);
                it->second--;
                if(it->second == 0) {
                    it = mp.erase(it);
                } else {
                    ++it;
                }
                p++;
                if(p == g) break;
            }
            // for(int i=0;i<temp.size();i++){
            //     cout<<temp[i]<<" ";

            // }
            // cout<<endl;
            for(int i=1;i<temp.size();i++){
                if(temp[i]-temp[i-1]!=1) return 0;

            }
            temp.clear();
        }
        return 1;
    }
};
