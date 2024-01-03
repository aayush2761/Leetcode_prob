class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        if(n<2) return 0;
        vector<int>v;
        for(int i=0;i<bank.size();i++){
            int c=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1')c++;
            }
           if(c>0) v.push_back(c);
        }
        if(v.size()<2) return 0;
        int ans=0;
        for(int i=0;i<v.size()-1;i++){
            ans = ans+ (v[i]*v[i+1]);
        }
     return ans;
    }
};