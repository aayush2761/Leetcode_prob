class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        map<int,int>st;
        for(auto i : nums) st[i]++;
        int res=INT_MIN;
        int total= accumulate(nums.begin(),nums.end(),0);
        for(auto i : nums){
            // 2x+y=total
            int x= (total-i);
            st[i]--;
            if(st[x/2] && x%2==0) res=max(res,i);

            st[i]++;
        }
        return res;
    }
};