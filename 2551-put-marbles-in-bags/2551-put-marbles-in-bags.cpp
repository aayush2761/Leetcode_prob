class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        priority_queue<int>maxPq;
        priority_queue<int, vector<int>,greater<int>>minPq;
        for(int i=1;i<nums.size();i++){
            int t= nums[i]+ nums[i-1];
            maxPq.push(t);
            minPq.push(t);
        }
        long long temp1=0, temp2=0;
        int p=k-1;
        k--;
        while(k-- && ! maxPq.empty()){
            temp1+=maxPq.top();
            maxPq.pop();
        }
        while(p-- && ! minPq.empty()){
            temp2+=minPq.top();
            minPq.pop();
        }
        return temp1-temp2;


    }
};

// [1,4,2,5,2]
// 3