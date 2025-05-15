class Solution {
public:
    vector<int> getRow(int r) {
        if(r==0)return {1};
        vector<int>prev={1};
        vector<int>curr;
        for(int i=1;i<=r;i++){
            int n= prev.size()+1;
            curr.resize(n);
            for(int j=0;j<n;j++){
                if(j==0)curr[j]=prev[0];
                else if ( j==n-1)curr[j]=prev[j-1];
                else curr[j]= prev[j-1]+ prev[j];
            }
            prev=curr;
        }
        return prev;
    }
};


