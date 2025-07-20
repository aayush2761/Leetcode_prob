class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int i=0,j=0;
        vector<int>res;
        while(i<nums.size()){
            while(!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
            if(i-j+1==k){
                res.push_back(dq.front());
                if(nums[j]== dq.front())dq.pop_front();
                j++;
            }
            i++;
        }
        // res.push_back(dq.back());
        return res;
    }
};