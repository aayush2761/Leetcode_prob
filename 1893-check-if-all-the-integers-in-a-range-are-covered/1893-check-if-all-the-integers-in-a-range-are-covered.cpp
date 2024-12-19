class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int maxi=INT_MIN;
        // for(auto i: ranges){
        //     maxi=max(i[0],max(i[1],maxi));
        // }
        vector<int>diff(50+1,0);
        if(50<right) return false;
        for(auto i : ranges){
            diff[i[0]]++;
            diff[i[1]+1]--;
        }
        for(int i=1;i<=50;i++)diff[i]+=diff[i-1];
        // for(int i=0;i<=50;i++) cout<<diff[i]<<" ";
        // cout<<endl;
        for(int i=left;i<=right;i++){
            if(diff[i]<1)return false;
        }
        return true;
    }
};