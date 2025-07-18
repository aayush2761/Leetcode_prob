class Solution {
public:
    void minLeft(vector<int>& nums, vector<long long>& left) {
        int n = nums.size() / 3;
        long long sum = 0;
        priority_queue<int> pq; 
        for (int i = 0; i < 2 * n; ++i) {
            sum += nums[i];
            pq.push(nums[i]);
            if (pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == n) // this was missing bruhh
                left[i] = sum;
        }
    }

    void maxRight(vector<int>& nums, vector<long long>& right) {
        int n = nums.size() / 3;
        int sz = nums.size();
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq; 
        for (int i = sz - 1; i >= n; --i) {
            sum += nums[i];
            pq.push(nums[i]);
            if (pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == n) // same  
                right[i] = sum;
        }
    }

    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int sz = nums.size();
        vector<long long> left(sz, 0), right(sz, 0);

        minLeft(nums, left);
        maxRight(nums, right);
        //  for(int i=0;i<left.size();i++)cout<<left[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<right.size();i++)cout<<right[i]<<" ";
        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            res = min(res, left[i] - right[i + 1]);
        }
        return res;
    }
};
