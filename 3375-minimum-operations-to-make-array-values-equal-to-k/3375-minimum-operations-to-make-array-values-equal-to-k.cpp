class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int m= *max_element(nums.begin(),nums.end());
        set<int>st(nums.begin(),nums.end());
        int x=0;
        for(auto i : st){
            if(i>k) x++;
            else if(i==k) continue;
            else return -1;
        }
        return x;
    }
};