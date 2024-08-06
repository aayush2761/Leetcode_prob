class Solution {
public:
    int minimumPushes(string word) {
        // hasing 
        vector<int>v(26,0);
        for(int i=0;i<word.size();i++){
            int t= word[i]-'a';
            v[t]++;
        }
        sort(v.rbegin(),v.rend());
        int res=0;
        // first eight 
        for(int i=0;i<8;i++){
            res+= v[i];
        }
        // next eight
        for(int i=8;i<16;i++){
            res+=(2*v[i]);
        }
        // next eight
        for(int i=16;i<24;i++){
            res+=(3*v[i]);
        }
        // last two 
        res+= 4*v[24] + 4*v[25];

        return res;
    }
};