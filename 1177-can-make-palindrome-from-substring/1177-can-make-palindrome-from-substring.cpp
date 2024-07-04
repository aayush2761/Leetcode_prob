class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>mp;
        vector<int>count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
            mp[i]=count;
        }
        int n=queries.size();
        vector<bool>ans(n);
        for(int i=0;i<n;i++)   
        {
            if(queries[i][0]!=0){
                int count_odd=0;
                for(int j=0;j<=25;j++){
                    if((mp[queries[i][1]][j]-mp[queries[i][0]-1][j])%2==1)count_odd++;
                }
                if(count_odd<=1)ans[i]=true;
                else if(count_odd/2<=queries[i][2])ans[i]=true;
                else ans[i]=false;
            }
            else{
                int count_odd=0;
                for(int j=0;j<=25;j++){
                    if(mp[queries[i][1]][j]%2==1)count_odd++;
                }
                if(count_odd<=1)ans[i]=true;
                else if(count_odd/2<=queries[i][2])ans[i]=true;
                else ans[i]=false;
            }
        }
        return ans;
    }
};

//https://www.youtube.com/watch?v=3Lx3EGMf6yI