class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int t1=0,t2=0;
        for(auto & it : nums){
            t1^=it;
            t2^=(it+1);
        }
        return t1==0 && t2==0;
    }
};