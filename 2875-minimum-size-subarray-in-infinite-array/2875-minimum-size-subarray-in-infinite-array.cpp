class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size(), ans = 0;
        long sum = 0;
        for(auto it : nums)
            sum += it;
        if(target > sum){
            ans += (target / sum) * n;
            target %= sum;
        }
        vector<int> vec(nums.begin(), nums.end());
        for(auto it : nums)
            vec.push_back(it);
        int i = 0, j = 0, size = 2 * n, mini = size + 1;
        long s = 0;
        while(j < size){
            s += vec[j];
            while(s > target)
                s -= vec[i++];
            if(s == target)
                mini = min(mini, j - i + 1);
            j++;
        }
        if(mini == size + 1)
            return -1;
        return ans + mini;
    }
};