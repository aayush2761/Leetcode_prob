class Solution {
public:
    int mod = 1000000007;
    int numSubseq(vector<int>& nums, int target) {
        int answer=0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>two(n+1,0);
        two[0]=1;
        for(int i=1;i<=n;i++)two[i]=( 2*two[i-1])%mod;
        for(int i=0;i<nums.size();i++){
            int req= target- nums[i];
            int index = upper_bound(nums.begin()+i, nums.end(), req)-nums.begin();
            // cout<<index<<endl;
            if(index<=i) continue;
            int length = index - i-1;
            // cout<<"len"<<length<<endl;
            answer= (answer+ (two[length])%mod)%mod;
        }
        return answer;
    }
};